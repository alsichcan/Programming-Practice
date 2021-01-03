#include <stdio.h>

int main(){
  char c;
  int line = 0;
  int aNum = 0;
  int space = 0;
  int num = 0;
  
  while((c = getchar()) != EOF){
    if (c == '\n') line = line + 1;
    else if (c == 'a') aNum = aNum+1;
    else if (c == ' ' || c == '\t') space = space + 1;
    else if ('0' <= c && c <= '9') num = num+1; 
  }

  printf("a: %d\n", aNum);
  printf("num: %d\n", num);
  printf("line: %d\n", line);
  printf("space: %d\n", space);
  
  return 0;
}