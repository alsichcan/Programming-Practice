#include <stdio.h>

int main(void){
  int num;
  int dgt[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

  scanf("%d", &num);

  int power = 0;
  while(num >= 2){
    dgt[14-power] = num % 2;
    num = num / 2;
    power++;
  }
  dgt[14-power] = 1;

  for(int i = 0; i < 15; i++){
    if(dgt[i] != -1)
      printf("%d", dgt[i]);
  }
  printf("\n");

}