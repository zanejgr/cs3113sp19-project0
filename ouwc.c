#include "proj0.h"
int main(int argc,char**argv)
{
	FILE*file;
	//check that the arguments are valid
	if(argc!=2&&argc!=3){
		perror("usage: ouwc [-l|-c] <file>");
		return EXIT_FAILURE;
	}
	//attempt to open the file, if any
	if(argc==2) file = stdin;
	if(argc==3&&!(file=fopen(argv[2],"r"))){
		perror("usage: ouwc [-l|-c] <file>");
		return EXIT_FAILURE;
	}
	//count lines or characters depending on argv[1]
	int count = 0;	
	char*strptr=NULL;
	size_t foo = 0;
	int numread = 0;
	while(numread=getline(&strptr,&foo,file)!=-1){
		if(!strncmp(argv[1],"-n",2)) count+=numread;
		else if(!strncmp(argv[1],"-l",2)) count++;
		else{
			perror("usage: ouwc [-l|-c] <file>");
			return EXIT_FAILURE;
		}	

	}
	printf("%d",count);
	return EXIT_SUCCESS;

}

