#include "proj0.h"
int ncat(FILE* file,int n);
int main(int argc,char**argv)
{
	int flag = 0;	//toggles if an invalid argument is specified
	FILE* file;
	int n = 10;
	//if there are enough arguments, and -n flag is specified
	if(argc>2&&argc<=4&&!strncmp(argv[1],"-n",2)){
		n=atoi(argv[2]);
		//insure that the number is specified and valid
		int flag = n==0&&strcmp(argv[2],"0");
		//ensure that if a file is specified then it is valid
		if(argc==4) flag=flag&&!(file=fopen(argv[3],"r"));
		else file=stdin;
	}else if(argc==1){
		file=stdin;

	}else if(argc==2){
		flag=!(file=fopen(argv[1],"r"));
	}
	if(flag){
		perror("usage: ouhead [-n N] <file>");
		return EXIT_FAILURE;
	}
	return ncat(file,n);
}
int ncat(FILE* file,int n){
	char*strptr=NULL;
	size_t foo = 0;
	while(n>0&&getline(&strptr,&foo,file)!=-1){
		fputs(strptr,stdout);
		n--;
	}
	return(EXIT_SUCCESS);
}

