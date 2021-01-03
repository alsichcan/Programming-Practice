#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
  int data;
  struct __node* next;
}node;

typedef struct __list{
  node* head;
  int cnt;
}list;

void push(list*, int);
int pop(list*);
void print_stack(list*);

int main(){
  list* stk = (list*)malloc(sizeof(list));
  if(!stk) printf("Failed to Init.\n");
  stk->head = NULL;
  stk->cnt = 0;

  push(stk, 1);
  push(stk, 3);
  push(stk, 5);
  push(stk, 7);
  print_stack(stk);

  return 0;
}

void push(list* stk, int val){
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    printf("Failed to create a node\n");
    return;
  }
  N->data = val;
  N->next = stk->head;
  stk->head = N;
  stk->cnt++;   
}

int pop(list* stk){
  if(stk->cnt == 0){
    printf("Stack is empty\n");
    return 0;
  }
  
  node* top = stk->head;
  int popVal = top->data;
  stk->head = top->next;
  free(top);

  stk->cnt--;

  return popVal;
}

void print_stack(list* stk){
  while(stk->cnt > 0){
    int printVal = pop(stk);
    if(printVal == 0)
      break;

    printf("%d", printVal);
    printf("\n");
  }
}