#include<stdio.h>

main() {
  int WT[10], BT[10], TA[10], TTA = 0, TWT = 0, AWT, pn[10], ATA, n, j, temp, i;
  printf("enter the value of n");
  scanf("%d", & n);
  printf("enter BT of n process \n");
  for (i = 1; i <= n; i++) {
    scanf("%d", & BT[i]);
    pn[i] = i;
  }
  for (i = 1; i < n; i++)
    for (j = i; j <= n; j++) {
      if (BT[i] > BT[j]) {
        temp = BT[i];
        BT[i] = BT[j];
        BT[j] = temp;
        temp = pn[i];
        pn[i] = pn[j];
        pn[j] = temp;
      }
    }
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
