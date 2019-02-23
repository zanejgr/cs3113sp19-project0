#include "proj0.h"
int cat(FILE *file);
int main(int argc, char**argv)
{
	
	if(argc == 1)
	cat(stdin);
	if(argc == 2 && strlen(argv[1])>=2 && !strncmp(argv[1],"-h",2)){
		fprintf(stdout,"usage: oucat <files>");
		return(EXIT_SUCCESS);
	}
	for(int i = 1; i < argc;i++){
		FILE* file;
		if(!(file=fopen(argv[i],"r"))){
			log_err();
			return -1;
		}

		cat(file);
	}
	return EXIT_SUCCESS;
}
int cat(FILE *file){
	char*strptr=NULL;
	size_t foo = 0;
	while(getline(&strptr,&foo,file)!=-1){
		fputs(strptr,stdout);
	}
	return(EXIT_SUCCESS);
}

