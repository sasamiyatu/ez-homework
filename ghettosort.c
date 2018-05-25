#include <stdio.h>

#define SIZE 10

void bsort(int ary[], int n);

int main() {


  //int array_size = 10;
  /*while (array_size <= 0) {
    printf("Enter array size: ");
    scanf("%d", &array_size);
  }*/
  
  int ary[SIZE] = {0};

  printf("Enter numbers into array: \n");
  int i = 0;
  for (i = 0; i < SIZE; ++i) {
    scanf("%d", &ary[i]);
  }


  bsort(ary, SIZE);

  printf("Result: ");
  for (i = 0; i < SIZE; ++i) {
    printf("%d ", ary[i]);
  }

  return 0;
}

void bsort(int ary[], int n) {
  
  

}
