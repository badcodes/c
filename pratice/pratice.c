#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int wmain()
{
	wint_t c;
	wchar_t *ustr=malloc(200);
	char *cstr;
	int l=0;
	int i=0;
	/*while((c=getwchar())!=WEOF){
		//putwchar(c);
		ustr[i++]=c;
	}
	ustr[i]=L'\0';*/
	ustr="¹¤aBÔÚ";
	wprintf(L"ustr:%s\n",ustr);
	cstr=(char*)ustr;
	l=10;
	for (i=0;i<l;i++){
		printf("[%d]=%hu\t",i,cstr[i]);
	}

	putchar('\n');
	l=wcslen(ustr);
	printf("strlen=%d\n",wcslen(ustr));
		for (i=0;i<l;i++){
		wprintf(L"[%d]=%hu\t",i,ustr[i]);
	}

	putchar('\n');
	cstr=(wchar_t *)ustr;
	printf("strlen=%d\n",strlen(cstr));
	l=10;
	for (i=0;i<l;i++){
		printf("[%d]=%hu\t",i,cstr[i]);
	}
	putchar('\n');
	return (0);
}