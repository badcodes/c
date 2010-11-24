/*
 * =====================================================================================
 * 
 *       Filename:  path.c
 * 
 *    Description:  path related functions
 * 
 *        Version:  1.0
 *        Created:  01/08/2007 08:56:34 PM HKT
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
#include <malloc.h>
#include "path.h"

int strindex(const char *s, char c)
{
    if (s == NULL)
	return -1;
    char *i = strchr(s, c);
    if (i == NULL)
	return -1;
    return (i - s);
}

int strrindex(const char *s, char c)
{
    if (s == NULL)
	return -1;
    char *i = strrchr(s, c);
    if (i == NULL)
	return -1;
    return (i - s);
}

char *dirname(const char *filename)
{
    if (filename == NULL)
	return strdup(".");

    char *result = strdup(filename);
    int c = strrindex(result, '/');
    while (c == strlen(result) - 1) {
	result[c] = '\0';
	c = strrindex(result, '/');
    }
    if (c < 0)
	return strdup(".");

    result[c] = '\0';
    return result;

}

char *basename(const char *filename)
{
    if (filename == NULL)
	return NULL;
    char *result = strdup(filename);

    int c = strrindex(result, '/');

    while (c == strlen(result) - 1) {
	result[c] = '\0';
	c = strrindex(result, '/');
    }

    if (c < 0)
	return result;
    else
	return result + c + 1;
}

char *buildpath(char *part1, char *part2)
{
    if (part1 == NULL && part2 == NULL)
	return NULL;
    if (part1 == NULL)
	part1 = "";
    if (part2 == NULL)
	part2 = "";
    char *result = (char *) malloc(strlen(part1) + strlen(part2) + 2);
    int c = strrindex(part1, '/');
    while (c == strlen(part1)) {
	part1[c] = '\0';
	c = strrindex(part1, '/');
    }
    c = strindex(part2, '/');
    while (c == 0) {
	part2++;
	c = strindex(part2, '/');
    }
    strcpy(result, part1);
    strcat(result, "/");
    strcat(result, part2);
    return result;
}
