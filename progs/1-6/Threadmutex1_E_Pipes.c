#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
main() {
  int rc1, rc2;
  pthread_t thread1, thread2;
  if ((rc1 = pthread_create( & thread1, NULL, & functionC, NULL))) {
    printf("Thread creation failed: %d\n", rc1);
  }
  if ((rc2 = pthread_create( & thread2, NULL, & functionC, NULL))) {
    printf("Thread creation failed: %d\n", rc2);
  }
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  exit(0);
}
void * functionC() {
  pthread_mutex_lock( & mutex1);
  counter++;
  printf("Counter value: %d\n", counter);
  pthread_mutex_unlock( & mutex1);
}

// cc Threadmutex1.c -lpthread 
======================================================================
#include<stdio.h>

main() {
  int pid, a[2], b[2], i = 5;
  char str[3], buff[3];
  pipe(a);
  pipe(b);
  pid = fork();
  if (pid == 0) {
    i = i + 10;
    sprintf(str, "%d", i);
    write(a[1], str, 3);
    sleep(5);
    read(b[0], str, 3);
    printf("response from server is %s \n", str);
  } else {
    read(a[0], buff, 3);
    printf("request from client is %s \n", buff);
    i = i + 15;
    sprintf(buff, "%d", i);
    write(b[1], buff, 3);
    wait();
  }
}
