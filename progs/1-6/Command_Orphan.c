#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<grp.h>
#include<pwd.h>

main(int argc, char * argv[]) {
  struct stat thebuf;
  char * path;
  int i;
  for (i = 1; i < argc; i++) {
    path = argv[i];
    if (!stat(path, & thebuf)) {
      printf("\n file mode of %s %d of which is ", argv[1], thebuf.st_mode);
      switch (thebuf.st_mode & S_IFMT) {
      case S_IFDIR:
        printf("\n A directory file");
        break;
      case S_IFCHR:
        printf("\n A character special file");
        break;
      case S_IFREG:
        printf(" \n an ordinary file");
        break;
      case S_IFBLK:
        printf("\n a block special file");
        break;
      case S_IFIFO:
        printf("\n a fifo file");
        Pg - 4
        break;
      case S_IFSOCK:
        printf("\n a socket");
        break;
      }
    } else
      printf("\n cant get state on %s ", path);
  }
}

===========================================================================
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

main() {
  int pid;
  printf("Demonstration of orphan process");
  pid = fork();
  if (pid == 0) {
    sleep(10);
    printf("child ID is %d \n ", getpid());
    printf("child parent ID is %d \n", getppid());
  } else {
    printf("parent ID is %d \n", getpid());
    printf("parent of parent process is %d \n", getppid());
  }
}
