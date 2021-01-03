#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int x1, y1, r1, x2, y2, r2;

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d", &r1, &r2);

  double distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

  if(distance < abs(r1-r2)){
    printf("교점이 없습니다.\n");
  } else if(distance == abs(r1-r2)){
    printf("교점이 하나 입니다.\n");
  } else if(distance < r1 + r2){
    printf("교점이 두 개 입니다.\n");
  } else if(distance == r1 + r2){
    printf("교점이 하나 입니다.\n");
  } else{
    printf("교점이 없습니다.\n");
  } 
  
  return 0;
}