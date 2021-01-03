#include <stdio.h>
#include <limits.h>

int main(void){
  int i;
  int n;
  int mask = 1 << 31;

  printf("n: ");
  scanf("%d", &n);

  int n2 = n;
  printf("<2진수>\n");
  for(i = 1; i <= 32; ++i){
    putchar(((n2 & mask)==0)? '0' :'1');
    n2 <<= 1;
    if(i % 8 == 0 && i < 32)
      putchar(' ');
  }

  printf("\n\n");

  int n16 = n;
  char hexaN[8] = {0,};

  printf("<16진수>\n");
  for(int i = 7; i >= 0; --i){
      int mod = n16 % 16;
      char dgt;

      if(mod < 10){
        dgt = 48 + mod;
      } else{
        dgt = 97 + (mod - 10);
      }

    hexaN[i] = dgt;
    n16 -= mod;
    n16 /= 16;
  }

  for(int i = 0; i < 8; ++i){
    putchar(hexaN[i]);
  }

  printf("\n\n");
}