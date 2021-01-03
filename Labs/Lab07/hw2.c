#include <stdio.h>

int sosu[5002];

int count_sosu(int n);

int main(void)
{
  int n=0;

  scanf("%d", &n);

  printf("Count : %d\n", count_sosu(n));

  return 0;
}

int count_sosu(int n)
{
  int count = 0;
  for(int i = 2; i <= n; i++){
    int isSosu = 1;
    for(int j = 2; j < i; j++){
      if(i % j == 0)
        isSosu = 0;
    }
    if(isSosu){
      printf("%d is sosu\n", i);
      count++;
    }
  }
  return count;
}