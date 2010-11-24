#include <tchar.h>
#define LINDEBUG
#define APPNAME "RVIEW"
#define APPDESC "控制台文本阅读工具,需要系统命令MORE"
#define APPVER "1.0.0"
#define APPCOPYRIGHT "CopyLeft @ FOREVER BY LiN MYPLACE"
#define APPINFO APPNAME " v" APPVER "\n" APPDESC "\n" APPCOPYRIGHT
#define APPHELP	"命令参数: [-h] [-l] [-v] [-r] [-z] [-n] [-p] [-more] [-less] [NUM] \n" \
						   "\t-h:\t\t\t显示本帮助\n"\
							"\t-l:\t\t\t显示列表\n"\
							"\t-v:\t\t\t显示配置\n"\
							"\t-r:\t\t\t以当前目录为工作目录\n"\
							"\t-z:\t\t\t随机模式\n"\
							"\t-n:\t\t\t读取下一个文件\n"\
							"\t-p:\t\t\t读取上一个文件\n"\
							"\t-c[viewer]:\t\t设置阅读程序的文件名，如: -cmore\n"\
							"\t-f[filename]:\t\t设置要读取的文件名，如: -freadme.txt\n"\
							"\t[NUM]:\t\t\t读取第NUM个文件"
#define DEFAULTVIEWER _T("more")
#define WILDNAME _T("*")
#define NIL _T('\0')

