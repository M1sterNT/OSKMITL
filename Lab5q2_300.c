#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main (){
   pid_t cpid;
   char ans = 'z';
    while (ans != 'q'){
 	printf("a. ls\nb. ps\nc. who\nq. exit\n");
	scanf("%c",&ans);
	while(getchar() != '\n');
    	switch(ans){
		case 'a':
		if((cpid = fork() )== 0){ execlp("/bin/ls","ls",NULL);
		exit(0);}		
       		break;
		case 'b':
		if((cpid = fork()) == 0) {execlp("/bin/ps","ls",NULL);	
	     	exit(0);}	
		break;
		case 'c':
		if((cpid = fork() )== 0){ execlp("/usr/bin/who","who",NULL);
		exit(0);}
		break;
		default :
		ans = 'q';
         	printf("Invalid\n" );
		}
	while(wait(NULL) != -1);
	}
}
