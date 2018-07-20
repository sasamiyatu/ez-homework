#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {
  int val = 0;
  int menu;
  do {
    printf("\n**** Stack management program****\n");
    printf("        1:push\n");
    printf("        2:pop\n\n");
    printf("        9:End\n");
    printf("Select a number ? ");
    if (scanf("%d", &menu) != 1) {
      menu = 0;
      while (getchar() != '\n')
        ;
    }

    switch(menu) {
    case 1:
      printf("Enter a value: ");
      scanf("%d", &val);
      push(val);
      print_stack();
      break;
    case 2:
      val = pop();
      if(val >= 0) {
        printf("You got a number:%d from stack.\n", val);
      }
      print_stack();
      break;
    case 9:
      break;
    default:
      menu = 0;
      break;
    }
  }while(menu != 9);
  return 0;
}
