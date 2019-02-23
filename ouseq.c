#include "proj0.h"
int main(int argc,char**argv)
{
	int m,n;
	//validate input first
	if(argc!=3&&argc!=2){
		fprintf(stderr,"usage: ouseq[M] N");
		return EXIT_FAILURE;
	}//m defaults to 0
	if(argc==2){
		m=0;
		n=atoi(argv[1]);
		if(n==0&&argv[1][sizeof argv[1]-1]!='0'){

			fprintf(stderr,"usage: ouseq[M] N");
			return EXIT_FAILURE;
		}
	}else{
		m=atoi(argv[1]);
		n=atoi(argv[2]);
		if(m==0&&argv[1][sizeof argv[1]-1]!='0'||
				n==0&&argv[2][sizeof argv[2]-1]!='0'){
			fprintf(stderr,"usage: ouseq[M] N");
			return EXIT_FAILURE;
		}
	}
	//special case:m=n
	if(m==n){
		printf("%d",m);
		return EXIT_SUCCESS;
	}
	
	int incr = m<n?1:-1;
	for(int i = m;i!=n+incr;i+=incr){
		printf("%d\n",i);
	}
	return EXIT_SUCCESS;
}

