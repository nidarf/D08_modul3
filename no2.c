#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/
pthread_t tid[10];

typedef struct inputan{
	int N;
	int T;
	int c;
}input;

void* playandcount(void *arg)
{
	struct inputan *lol =  (struct inputan*)arg;
 	   pthread_t id=pthread_self();
	if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
   	{
		int j , i ,  isPrime;
		for(i = 2; i <= lol->N/lol->T; i++){
        	isPrime = 0;
        		for(j = 2; j <= i/2; j++){
  		           if(i % j == 0){
  		               isPrime = 1;
  		               break;
  		      	     }
  	     	 }
  	        
    	        if(isPrime==0 && lol->N!= 1)
  	        printf("%d ",i);

	  }}else{
		
		int j,i,isPrime;
			pthread_equal(id,tid[lol->c]);
			for(i = lol->c*lol->N/lol->T ; i <= (lol->c+1)*lol->N/lol->T; i++){
        		isPrime = 0;
        			for(j = 2 ; j <= i/2; j++){
  		           		
					if(i % j == 0){
  		               		isPrime = 1;
  		              		 break;
  		      	     			}
  	     	 			}
  	        
    	       			 if(isPrime==0 && lol->N!= 1)
  	       			 printf("%d ",i);
				}
		++lol->c ;
    }
	printf("\n");

    return NULL;
}
int main(void)
{
    input lol;
    int i=0;
    int err;
	scanf("%d",&lol.T);
	int N;
	scanf("%d",&lol.N);
	lol.c =1;

    while(i<lol.T)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,&lol);//membuat thread
        i++;
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
return 0;
}
