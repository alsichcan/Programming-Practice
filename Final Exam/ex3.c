//
// Created by Park on 2020-12-15.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fibonacci(int);

char c1, c2;
int k;
char* str;

int main(void){
    scanf("%c %c %d", &c1, &c2, &k);

    str = fibonacci(k);

    for(int i = 0; str[i]; i++){
        printf("%c", str[i]);
    }

    return 0;
}

char* fibonacci(int k){
    char* retStr;

    if(k == 0){
        retStr = (char*) calloc(sizeof(char), 1);
        retStr[0] = c1;
    } else if(k == 1){
        retStr = (char*) calloc(sizeof(char), 1);
        retStr[0] = c2;
    } else retStr = strcat(fibonacci(k-2), fibonacci(k-1));

    return retStr;
}