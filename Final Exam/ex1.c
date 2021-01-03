//
// Created by Park on 2020-12-15.
//
#include <stdio.h>
#include <ctype.h>

void print(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = toupper(str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = tolower(str[i]);
        else {
            continue;
        }
    }

    for (int i = 0; str[i]; i++) {
        printf("%c", str[i]);
    }
}