//Prog 1
#include<stdio.h>
#include<unistd.h>

int main() {
  pid_t ret_value;
  printf(“\n The process id is % d\ n”, getpid());
  ret_value = fork();
  if (ret_value < 0) {
    printf(“\n Fork Failure\ n”);
  }
  elseif(ret_value == 0) {
    //child process
    printf(“\n child process\ n”);
    printf(“the process id is % d\ n”, getpid());
    sleep(20);
  }
  else {
    //parent process
    printf(“parent process\ n”);
    printf(“the process id is % d\ n”, getpid());
    sleep(30);
  }
  return 0;
}

==============================================================================
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

main() {
  int pid, msgid;
  char a[20], buf[20];
  msgid = msgget((key_t) 59, IPC_CREAT | 0600);
  pid = fork();
  if (pid == 0) {
    strcpy(a, "1604-13-733-059");
    msgsnd(msgid, & a, 15, IPC_NOWAIT);
    sleep(1);
    msgrcv(msgid, & a, 15, 0, 0);
    printf("response from server is %s \n", a);
  } else {
    msgrcv(msgid, & buf, 15, 0, 0);
    printf("response from client is %s \n", buf);
    strcpy(buf, "pass");
    msgsnd(msgid, & buf, 15, IPC_NOWAIT);
    wait();
  }
}
  
