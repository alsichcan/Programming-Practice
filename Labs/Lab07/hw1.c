#include <stdio.h>

int read_and_calc();

int main(void){
  printf("result: %d\n", read_and_calc());

  return 0;
}

int read_and_calc(void){
  int value = 0;
  
  char operator;
  char operand;

  value += getchar() - '0'; 
  while((operator = getchar()) != EOF && (operand = getchar()) != EOF){
    if(operator == '+')
      value += operand - '0';
    else if(operator == '-')
      value -= operand - '0';
  }  
  return value;
}