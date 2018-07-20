#include <stdio.h>
#include "stack.h"

int stack[10] = {0};
int next_index = 0;

void push(int val) {

  if (val < 0) {
    printf("Enter a positive value!\n");
    return;
  }
  if (next_index >= MAXBUF) {
    printf("Error: Stack overflow!\n");
    return;
  }

  stack[next_index] = val;
  ++next_index;
}

int pop(void){
  if(next_index == 0) {
    printf("Error: Stack is empty\n");
    return -1;
  }
  int pop = stack[next_index-1];
  stack[next_index-1] = 0;
  --next_index;
  return pop;
}

void print_stack(void) {
  printf("+-------------------\n");
  printf("|");
  int i = 0;
  for (i = 0; i < next_index; ++i) {
    printf("%d ", stack[i]);
  }
  printf("\n");
  printf("+-------------------\n");
}
