#include "proj0.h"
int main(int argc,char ** argv)
{
	if(argc==1){
		puts("");
		return 0;
	}
	for(int i = 1; i < argc-1;i++)
		printf("%s ",argv[i]);
	printf("%s",argv[argc-1]);
	return 0;
}

