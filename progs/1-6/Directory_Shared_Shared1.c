#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<fcntl.h>

main(int argc, char * argv[]) {
    struct dirent * direntp;
    DIR * dirp;
    if (argc != 2) {
      printf("ussage %s directory name \n", argv[0]);
      return 1;
    }
    if ((dirp = opendir(argv[1])) == NULL) {
      perror("Failed to open directory\
        n "); return 1;
      }
      while ((direntp = readdir(dirp)) != NULL)
        printf("%s\n", direntp -> d_name);
      while ((closedir(dirp) == -1) && (errno == EINTR))
      ;
      return 0;
    }
============================================================================
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

main() {
  char * s;
  int shmid = shmget(1234, 20, IPC_CREAT | 0666);
  s = shmat(shmid, NULL, 0);
  printf("Enter a msg: \n");
  scanf("%s", s);
}
============================================================================
//shared1.c

#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
main() {
char *s;
int shmid=shmget(1234,20,IPC_CREAT|0666);
s=shmat(shmid,NULL,0);
printf("Entered msg: %s \n",s);
}
