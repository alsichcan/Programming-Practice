//
// Created by Park on 2020-12-15.
//
#include <stdio.h>

int main(void){
    int prevNum;
    int currNum;
    int currMaxLen = 0;
    int maxLen = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", &currNum);
        if(i == 0){
            prevNum = currNum;
            currMaxLen = 1;
            maxLen = 1;
            continue;
        }

        if(prevNum + 1 == currNum){
            prevNum = currNum;
            currMaxLen++;
            if(maxLen < currMaxLen)
                maxLen = currMaxLen;

        } else{
            prevNum = currNum;
            currMaxLen = 1;
        }
    }

    printf("%d", maxLen);
}