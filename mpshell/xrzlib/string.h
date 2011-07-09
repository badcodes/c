
#ifndef LIBBASE_INCLUDE_STRING
#define LIBBASE_INCLUDE_STRING

	typedef char* string;

	int stridx(const string s1,const string s2);
	int strridx(const string s1,const string s2);
	string dstrcat(const string str, ...);
	string dstrrpl(const string str,const string s1,const string s2);
    

#endif
