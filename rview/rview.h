#include <tchar.h>
#define LINDEBUG
#define APPNAME "RVIEW"
#define APPDESC "����̨�ı��Ķ�����,��Ҫϵͳ����MORE"
#define APPVER "1.0.0"
#define APPCOPYRIGHT "CopyLeft @ FOREVER BY LiN MYPLACE"
#define APPINFO APPNAME " v" APPVER "\n" APPDESC "\n" APPCOPYRIGHT
#define APPHELP	"�������: [-h] [-l] [-v] [-r] [-z] [-n] [-p] [-more] [-less] [NUM] \n" \
						   "\t-h:\t\t\t��ʾ������\n"\
							"\t-l:\t\t\t��ʾ�б�\n"\
							"\t-v:\t\t\t��ʾ����\n"\
							"\t-r:\t\t\t�Ե�ǰĿ¼Ϊ����Ŀ¼\n"\
							"\t-z:\t\t\t���ģʽ\n"\
							"\t-n:\t\t\t��ȡ��һ���ļ�\n"\
							"\t-p:\t\t\t��ȡ��һ���ļ�\n"\
							"\t-c[viewer]:\t\t�����Ķ�������ļ�������: -cmore\n"\
							"\t-f[filename]:\t\t����Ҫ��ȡ���ļ�������: -freadme.txt\n"\
							"\t[NUM]:\t\t\t��ȡ��NUM���ļ�"
#define DEFAULTVIEWER _T("more")
#define WILDNAME _T("*")
#define NIL _T('\0')

