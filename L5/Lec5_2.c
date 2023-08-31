/*
Description: 
  Rewrite this program as stated in the course video
Sample: 
*/

#include <stdio.h>

void swap(int *aPrt, int *bPrt){
  int temp;
  temp = *aPrt;
  *aPrt = *bPrt;
  *bPrt = temp;
}

int main(void) {
  int x, y;
  int *xPrt = &x, *yPrt = &y;
  scanf("%d %d", &x, &y);

  swap(xPrt,yPrt);
  printf("x=%d, y=%d\n", *xPrt, *yPrt);

  return 0;
}
