#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param);

int main(int argc,char *argv[]){
	int n = atoi(argv[1]);
	int msum = 0;
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_create(&tid,&attr,runner,argv[1]);

	pthread_join(tid,NULL);
	int i ;
	for(i = 1; i<=(2*n);i++) msum += i ; 
	printf("my msum = %d\n",msum);
}
void *runner(void *param){
	int n = atoi(param);
	int csum = 0;
	int i ;
	for(i = 1;i<=n;i++) csum += i;
	printf("my csum = %d\n",csum);
	pthread_exit(0);

}
