//5th prog
#include<pthread.h>
#include<stdio.h>

#define NUM_THREADS 3
int je, jo, evensum = 0, sumn = 0, oddsum = 0, evenarr[50], oddarr[50];
void * Even(void * threadid) {
  int i, n;
  je = 0;
  n = (int) threadid;
  for (i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      evenarr[je] = i;
      evensum = evensum + i;
      je++;
    }
  }
}
void * Odd(void * threadid) {
  int i, n;
  jo = 0;
  n = (int) threadid;
  for (i = 0; i <= n; i++) {
    if (i % 2 != 0) {
      oddarr[jo] = i;
      oddsum = oddsum + i;
      jo++;
    }
  }
}
Pg - 13
void * SumN(void * threadid) {
  int i, n;
  n = (int) threadid;
  for (i = 1; i <= n; i++) {
    sumn = sumn + i;
  }
}
int main() {
  pthread_t threads[NUM_THREADS];
  int i, t;
  printf("enter a number\n");
  scanf("%d", & t);
  pthread_create( & threads[0], NULL, Even, (void * ) t);
  pthread_create( & threads[1], NULL, Odd, (void * ) t);
  pthread_create( & threads[2], NULL, SumN, (void * ) t);
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("the sum of first N natural nos is %d\n", sumn);
  printf("the sum of first N even natural nos is %d\n", evensum);
  printf("the sum of first N odd natural nos is %d\n", oddsum);
  printf("the first N even natural nos is \n");
  for (i = 0; i < je; i++)
    printf("%d\n", evenarr[i]);
  printf("the first N odd natural nos is: \n");
  for (i = 0; i < jo; i++)
    printf("%d\n", oddarr[i]);
  Pg - 14
  pthread_exit(NULL);
}

// cc multithread.c -lpthread 
=====================================================================================
#include<stdio.h>
#include<unistd.h>
main(){
  char *temp[3];
  temp[0]="ls";
  temp[1]="-l";
  temp[2]=(char *)0;
  execv("/bin/ls",temp);
  printf("this will not print\n");
}
