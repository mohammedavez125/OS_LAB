//6th prog
#include<stdio.h>

main() {
  int WT[10], BT[10], TA[10], TTA = 0, TWT = 0, AWT, ATA, n, i;
  printf("enter the value of n");
  scanf("%d", & n);
  printf("enter BT of n process \n");
  for (i = 1; i <= n; i++)
    scanf("%d", & BT[i]);
  WT[1] = 0;
  TA[1] = BT[1] + WT[1];
  for (i = 2; i <= n; i++) {
    WT[i] = BT[i - 1] + WT[i - 1];
    TA[i] = BT[i] + WT[i];
    TWT = TWT + WT[i];
    TTA = TTA + TA[i];
  }
  AWT = TWT / n;
  ATA = TTA / n;
  printf("Process no.\t Burst time\t Waiting time\t Turnaround time\n");
  for (i = 1; i <= n; i++) {
    printf("%d\t %d\t %d\t %d\t", i, BT[i], WT[i], TA[i]);
    printf("\n");
  }
}
======================================================================================
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

main() {
  int pid;
  printf("\n Demonstration of fork system call \n");
  pid = fork();
  if (pid < 0) {
    printf("\n not possible \n");
    exit(0);
  } else
  if (pid == 0) {
    sleep(5);
    printf("child processor ID is %d \n", getpid());
    printf("parent processor ID is %d \n", getppid());
  } else {
    wait();
    printf("parent id is %d", getpid());
    printf("\nparent of parent processor ID is %d\n", getppid());
  }
}
