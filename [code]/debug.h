#include <stdio.h>

#ifndef _LIN_INC_DEBUG
	#define _LIN_INC_DEBUG
	#ifdef LINDEBUG
		/* 
		DEBUGStr(myname)->
			DEBUGPrint("=%s\n",myname) ->
				_tprintf("myname" "=%s\n",myname);
		*/
		#define DEBUGPrint(fmt,exp) printf(#exp fmt,exp);
		#define DEBUGStr(exp) DEBUGPrint("=%s\n",exp);
		#define DEBUGInt(exp) DEBUGPrint("=%d\n",exp);
		#define PAUSE system("pause");
	#else
		#define DEBUGPrint(fmt,exp)
		#define DEBUGStr(exp)
		#define DEBUGInt(exp)
		#define PAUSE
	#endif
#endif
