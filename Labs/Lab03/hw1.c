#include <stdio.h>

int main(void){
  int num1;
  int num2;
  int val1;
  int val2;
  int val3;

  scanf("%d%d", &num1, &num2);
  val1 = num1 * (num2%10);
  val2 = num1 * (num2/10);
  val3 = num1 * num2;

  printf("%d \n", val1);
  printf("%d \n", val2);
  printf("%d \n", val3);


}