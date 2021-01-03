#include <stdio.h>
#include <math.h>

int main(void){
  int input1;
  int input2;

  int n1[32] = {0,};
  int n2[32] = {0,};
  int result[32] = {0,};

  printf("Input 1 : ");
  scanf("%d", &input1);

  printf("Input 2 : ");
  scanf("%d", &input2);

  for(int i = 31; i >= 0; i--){
    n1[i] = input1 % 10;
    n2[i] = input2 % 10;

    input1 /= 10;
    input2 /= 10;
  }

  for(int i = 31; i >= 0; i--){
    int sum = n1[i] + n2[i] + result[i];
    if(sum >= 2){
      result[i-1] += 1;
      result[i] = sum - 2;
    } else{
      result[i] = sum;
    }
  }

  printf("\n");
  printf("Result : ");
  int resultInt = 0;
  int startPrint = 0;
  for(int i = 0; i < 32; i++){
    if(!startPrint){
      if(result[i] == 0){
        continue;
      } else{
        startPrint = 1;
      }
    }

    resultInt += result[i] * (int) pow((double) 2, (double) 31-i);
    printf("%d", result[i]);
  }
  printf(" (%d)\n", resultInt);
}