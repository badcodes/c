#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "string.h"

int stridx(const string s1,const string s2) {
    string pos;

    if(s1==NULL) return -1;
    if(s2==NULL) return -1;

    pos=strstr(s1,s2);
    if(pos==NULL) return -1;

    return pos - s1;
}

int strridx(const string s1,const string s2) {
    int pos;
    string r1;
    string r2;
    int l1;
    int l2;

    if(s1==NULL) return -1;
    if(s2==NULL) return -1;

    l1=strlen(s1);
    l2=strlen(s2);
    if(l1<l2) return -1;
    if(l1==l2) {
        if(strcmp(s1,s2)==0) return 0;
        return -1;
    }

    r1=strrev(strdup(s1));
    r2=strrev(strdup(s2));
    pos=stridx(r1,r2);
    free(r1);
    free(r2);

    if(pos==-1) {
        return -1;
    }
    else {
        return (l1 - l2 - pos);
    }

}

string dstrrpl(const string str,const string txt,const string cs3) {
    int l_str,l_txt,l_rpl;
    string result;
    int match;
    int* apos;
    int i,o1,o2;
    string rpl = cs3;

    if(str==NULL) return str;
    if(txt==NULL) return str;
    if(rpl==NULL) rpl="";
    if(strcmp(txt,rpl)==0) return str;

    l_str = strlen(str);
    l_txt = strlen(txt);
    match = l_str / l_txt;
    if(match < 1) return str;

    apos = (int*)(malloc(sizeof(int)*match + 1));
    apos[0] = -l_txt;
    match = 0;
    o2 = 0;
    while((i = stridx(str + o2,txt)) > -1) {
        apos[++match] = i;
        o2 += apos[match] + l_txt;
    }
    if(match==0) return str;

    l_rpl = strlen(rpl);
    result = (char*)(malloc(sizeof(char)*(l_str - (l_txt - l_rpl)*match +1)));
    apos[0] = -l_txt;
    o1=0;
    o2=0;
    for(i=1;i<=match;i++) {
        memcpy(result+o1,str+o2,apos[i]);
        o1 = o1 + apos[i];
        o2 = o2 + apos[i];
        memcpy(result+o1,rpl,l_rpl);
        o1 = o1 + l_rpl;
        o2 = o2 + l_txt;
    }
    memcpy(result + o1,str+o2,l_str - o2 + 1);
    result[o1 + l_str - o2 + 1]=0;
    return result;
}


