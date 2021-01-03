#include <stdio.h>

#define STACK_SIZE 20

void push(int*, int);
int pop(int*);
void print_stack(int*);

int stk[STACK_SIZE];
int top = -1;

int main(){
  push(stk, 1);
  push(stk, 3);
  push(stk, 5);
  push(stk, 7);
  print_stack(stk);

  return 0;
}

void push(int* stk, int val){
  if(top >= STACK_SIZE-1){
    printf("Stack is full.\n");
  }
  top++;
  stk[top] = val;

}

int pop(int* stk){
  if(top == -1){
    return 0;
  }

  int popVal = stk[top];
  stk[top] = 0;
  top--;
  return popVal;
}

void print_stack(int* stk){
  while(top >= 0){
    int printVal = pop(stk);
    if(printVal == 0)
      break;

    printf("%d", printVal);
    printf("\n");
  }
}


