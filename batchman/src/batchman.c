
/*
 * =====================================================================================
 *
 *       Filename:  batchman.c
 *
 *    Description: batchman Main()
 *
 *        Version:  1.0
 *        Created:  01/06/2007 05:39:51 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include "config.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>
#include <getopt.h>

#include "list.h"
#include "queue.h"
#include "addtask.h"
#include "history.h"
#include "readkey.h"
#include "dotask.h"
#include "batchman.h"

#ifdef PROCESS_INPUT
#include "readkey.h"
int process_input()
{
    char *cmd =  readline();
    if (cmd == NULL)
	return 1;
    if (strcmp(cmd, "quit\n") == 0) {
	APPMSG("Please waiting for a second...\n");
        free(cmd);
	return 0;
    } else if (strcmp(cmd, "help\n") == 0) {
	APPMSG("Commands Below Available:\n");
	APPMSG("help \tDisplay this information\n");
	APPMSG("quit \tQuit the programe\n");
        free(cmd);
	return 1;
    } else {
	system(cmd);
        free(cmd);
	return 1;
     }
} 
#else
#define process_input() 1
#endif


int app_terminated = 0;


const int SLEEP = 1;

void before_terminated(int signum)
{
    switch (signum) {
    case SIGKILL:
    case SIGTERM:
        APPMSG("Warning: Receive termination signal\n");
        app_terminated = 1;
        break;
    case SIGINT:
        APPMSG("Warning: Receive interruption signal\n");
        app_terminated = 1;
        break;
    case SIGTTIN:
//        APPMSG("Warning: Runing in Background,ingore input...\n");
        break;
    default:
        break;
    }
}

void app_usage()
{
    printf("%s\n", PACKAGE_STRING);
    printf("Usage:\t%s [option] [working directory]\n", PACKAGE_NAME);
    printf("-h,--help\t\tDisplay this\n");
    printf("-t,--task-handler\tSpecify the task handler\n");
    printf("-w,--working-dir\tSpecify the working directory\n");
    printf("\nWritten by %s.\n", AUTHOR);
    printf("Last Build on %s\n.", PACKAGE_BUILDDATE);
    printf("For any bug, reporting to %s is always welcome.\n",
	   PACKAGE_BUGREPORT);
    return;
}


int main(int argc, char *argv[])
{

    signal(SIGTERM, before_terminated);
    signal(SIGKILL, before_terminated);
    signal(SIGINT, before_terminated);
    signal(SIGTTIN,before_terminated);

    char *taskhandler = NULL;
    char *taskfile = NULL;
    char *historyfile = NULL;
    char *taskincome = NULL;
    char *workingdir = NULL;

    int opt;
    while (1) {
	struct option long_option[] = {
	    {"help", no_argument, 0, 'h'},
	    {"task-handler", optional_argument, 0, 't'},
	    {"working-dir", optional_argument, 0, 'd'},
	    {0, 0, 0, 0}
	};
	int opt_index = 0;
	opt = getopt_long(argc, argv, "ht:d:", long_option, &opt_index);
	if (opt == -1)
	    break;
	switch (opt) {
	case 0:
	    break;
	case 't':
	    taskhandler = optarg;
	    break;
	case 'd':
	    workingdir = optarg;
	    break;
	case 'h':
	    app_usage();
	    return 0;
	default:
	    abort();
	}

    }
    if (optind < argc && taskhandler == NULL)
	taskhandler = argv[optind++];

    if (workingdir == NULL)
	workingdir = getcwd(NULL, 0);
    if (taskhandler == NULL)
	taskhandler = TASKHANDLER;

    mkdir(workingdir, S_IRWXU);

    if (chdir(workingdir) != 0) {
	APPMSG("Error: Unable to work under %s\n", workingdir);
	return EXIT_FAILURE;
    }

    historyfile =
	(char *) malloc(strlen(workingdir) + strlen(HISTORYFILE) + 2);
    sprintf(historyfile, "%s/%s", workingdir, HISTORYFILE);
    taskfile = (char *) malloc(strlen(workingdir) + strlen(TASKFILE) + 2);
    sprintf(taskfile, "%s/%s", workingdir, TASKFILE);
    taskincome =
	(char *) malloc(strlen(workingdir) + strlen(TASKINCOME) + 2);
    sprintf(taskincome, "%s/%s", workingdir, TASKINCOME);

    FILE *income = fopen(taskincome, "w");
    if (income == NULL) {
	APPMSG("Error: Unable to open %s for writing.\n", taskincome);
	return EXIT_FAILURE;
    } else {
	fputs("Nothing...\n", income);
	fclose(income);
    }

    APPMSG("Notifier: %s\n", taskincome);
    APPMSG("Hisotry File: %s\n", historyfile);
    APPMSG("Using %s\n", taskhandler);
    APPMSG("Listening on %s\n", taskfile);

    Queue *strBase = (Queue *) malloc(sizeof(Queue));
    queue_init(strBase);

    FILE *record = fopen(historyfile, "a");

    while (process_input() && !app_terminated) {
	FILE *income = fopen(taskincome, "r");

	if (income != NULL) {
	    fclose(income);
	    unlink(taskincome);
	    if (addtask(strBase, taskfile) != 0) {
		APPMSG("Read/Write Access Denied\n");
		APPMSG("Quit\n");
		return -1;
	    }
	}
	if (!queue_is_empty(strBase)) {
	    char *curtask = queue_out(strBase);

	    remember(curtask, record);
	    APPMSG("%s\n", curtask);
	    int child_exit_status = dotask(curtask, taskhandler);

	    if (child_exit_status != 0) {
		remember("\t[Failed]\n", record);
		APPMSG("Failed runing %s %s.\n", taskhandler, curtask);
		if (WIFSIGNALED(child_exit_status)
		    || WTERMSIG(child_exit_status)) {
		    APPMSG("Maybe terminated.\n");
		    APPMSG("Quit? [y]");
		    int answer = tolower(getchar());
		    int c = answer;

		    while (c != '\n' && c != EOF)
			c = getchar();
		    if (answer == 'y') {
                        queue_in(strdup(curtask),strBase);
			free(curtask);
			break;
		    }
		}
	    } else {
		APPMSG("Done,have %d task(s) left.\n",queue_length(strBase));
		remember("\t[Succeeded]\n", record);
	    }
	    free(curtask);
	} 
        /*else {
	    inc++;
	    if (inc > 60) {
		inc = 0;
		APPMSG("No task left. Falling sleep.\n");
	    }
	    sleep(SLEEP);
	}*/
    }

    fclose(record);
    unlink(taskincome);

    FILE *task = fopen(taskfile, "a");

    if (task != NULL) {
	while (!queue_is_empty(strBase)) {
	    char *curtask = queue_out(strBase);

	    if (curtask != NULL) {
		APPMSG("Saving Task Num.%d :%s\n", queue_length(strBase),
		       curtask);
		fputs(curtask, task);
		fputs("\n", task);
		free(curtask);
	    }
	}
	fclose(task);
    }

    APPMSG("Cleaning up Everything\n");
/*  queue_clean(strBase);
    free(strBase);
    free(historyfile);
    free(taskfile);
*/

    APPMSG("Leaving the world\n");
    APPMSG("Bye\n");
    return 0;
}

