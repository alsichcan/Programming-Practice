#include <stdio.h>
#include <string.h>

void swap(char**, char**);
void bubble_sort(char* words[10]);

int main(void){
  char* words[10] ={
    "computer", "windows", "window", "linux",
    "apple", "banana", "time", "help",
    "game", "money"
  };
  bubble_sort(words);
  for(int i = 0; i < 10; i++){
    printf("%s\n", words[i]);
  }
}

void swap(char** a, char** b){
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble_sort(char* words[10]){
   int i,j;
   
   for(i = 0; i < 9; ++i){
     for(j = 9; j > i; --j){
       if(strlen(words[j-1]) > strlen(words[j])) {
          swap(&words[j-1], &words[j]);
        } else if(strlen(words[j-1]) == strlen(words[j]) && strcmp(words[j-1], words[j]) > 0){
          swap(&words[j-1], &words[j]);
        }
      } 
    }
}