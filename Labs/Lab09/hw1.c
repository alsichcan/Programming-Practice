#include <stdio.h>
#include <string.h>

int main(void){
  char word[100];

  printf("input string: ");
  scanf("%s", word);

  int length = 0;
  int result = 1;

  for(int i = 0; word[i]; i++){
    length++;
  }

  for(int i = 0; i < length; i++){
    if(word[i] != word[length-i-1]){
      result = 0;
    }
  }

  if(result){
    printf("%s is a symmetrical word\n", word);
  } else{
    printf("%s is not a symmetrical word\n", word);
  }






}