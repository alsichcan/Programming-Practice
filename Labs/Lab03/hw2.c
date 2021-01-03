#include <stdio.h>

int main(void){
  int num;
  char key;

  scanf("%d", &num);
  key = num + 101;

  if(key>122){
    key -= 26;
  }

  printf("%c \n", key);





}