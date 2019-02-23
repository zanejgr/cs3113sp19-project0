#include "proj0.h"
#define gnu_source
int main(int argc,char**argv)
{
	int flag = 0;	//toggles if an invalid argument is specified
	FILE* file;
	int n = 10;
	//if there are enough arguments, and -n flag is specified
	if(argc>4){
		perror("usage: outail [-n N] <file>");
		return EXIT_FAILURE;
	}
	if(argc>2&&argc<=4&&!strncmp(argv[1],"-n",2)){
		n=atoi(argv[2]);
		puts("converted N to an integer");
		printf("Value = %d\n",n);
		//insure that the number is specified and valid
		int flag = n==0&&strcmp(argv[2],"0");
		//ensure that if a file is specified then it is valid
		if(argc==4) flag=flag&&!(file=fopen(argv[3],"r"));
		else file=stdin;
	}else if(argc==2){
		flag=!(file=fopen(argv[1],"r"));
	}else
		file=stdin;
	if(flag){
		perror("usage: outail [-n N] <file>");
		return EXIT_FAILURE;
	}
	printf("Arguments processed! N=%d\n",n);
	//iterate across the file, pushing each line into a buffer
	char**buf[n];	//I'm too sleepy to implement a stack right now.
	for(int i = 0; i < n; i++)	buf[n]=	malloc(1);
	size_t foo = 0;
	int index = 0;
	while(getline(buf[(index++)%n],&foo,file)!=-1){
		printf("in the read loop: %d lines read",index);
		foo=0;
	}
	printf("left the loop with code %d",errno);
	puts(strerror(errno));
	index--;
	//if the file has fewer than n lines
	if(index<n)
		for(int i = 0; i < index; i++) puts(*buf[i]);
	else
		for(int i = index%n; i < index%n+n; i++) puts(*buf[i%n]);
	return EXIT_SUCCESS;
}



