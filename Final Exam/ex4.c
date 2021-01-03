//
// Created by Park on 2020-12-15.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node* next;
}node;

typedef struct __list{
    int cnt;
    node* head;
} list;

push_stk(list*, int);

int main(void){
    list* stack = (list*) malloc(sizeof(list));
    if(!stack) printf("Stack not initialized\n");

    push_stk(stack, 1);
    push_stk(stack, 2);
    push_stk(stack, 3);

    while(stack->head){
        node* tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }
    free(stack);

    return 0;
}

push_stk(list* stack, int elem){
    node* N = (node*) malloc(sizeof(stack));
    if(!N) printf("Node not initialized\n");

    N->data = elem;
    N->next = stack->head;
    stack->head = N;
    stack->cnt++;
}