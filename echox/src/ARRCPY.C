
void arrcpy(char* dstarr,int *start,char* src) {
	while(*src) 
		dstarr[(*start)++] = *(src++);
}