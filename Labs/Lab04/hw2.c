#include <stdio.h>

int main(void){
  for(int i = 0; i < 5 ; i++){
    for(int blank = 0; blank < i; blank++){
      printf(" ");
    }
    for(int j = i ; j < 9-i; j++){
      printf("*");
    }
    for(int blank = 9-i; blank < 9; blank++){
      printf(" ");
    }
    printf("\n");
  }

  for(int i = 3; i >= 0; i--){
    for(int blank = 0; blank < i; blank++){
      printf(" ");
    }

    for(int j = i ; j < 9-i; j++){
      printf("*");
    }

    for(int blank = 9-i; blank < 9; blank++){
      printf(" ");
    }
    printf("\n");
  }
}