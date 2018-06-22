#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int inArray(int *array, int number, int array_size) {

  int i = 0;
  for (i = 0; i < array_size; ++i) {
    if(array[i] == number) {
      return 1;
    }
  }
  return 0;
}

int * nDigitRandomArray(int n) {
  int *array = ((int*)malloc(sizeof(int)*n));
  int i = 0;
  for (i = 0; i < n; ++i) {
    array[i] = -1;
  }
  srand(time(NULL));
  int used_numbers[10] = {-1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1};

  for (i = 0; i < n; ++i) {
    int new_digit = rand() % (9 + 1);
    while (inArray(used_numbers, new_digit, n) == 1) {
      new_digit = rand() % (9 + 1);
      //printf("Rolled %d for slot %d\n",new_digit, i);
    }
    array[i] = new_digit;
    used_numbers[i] = new_digit;
  }
  return array;
}

int main(int argc, char *argv[]) {

  int hit = 0;
  int blow = 0;
  
  int array_size = atoi(argv[1]);
  if (array_size < 1 || array_size > 10) {
    printf("Insert a number between 1 and 10 as argument \n");
    return 1;
  }
  int *array = nDigitRandomArray(array_size);

  int i = 0;
  /* for (i = 0; i < array_size; ++i) {
    printf("%d ", array[i]);
  }*/

  char guess[array_size];
  // printf("Array size: %d", array_size);

  int number_of_guesses = 0;

  while ( hit != array_size) {
    hit = 0;
    blow = 0;
    printf("Insert a %d digit number: ", array_size);
    scanf("%s", guess);
    if (strlen(guess) != array_size) {
      printf("Check your string length bro \n");
      continue;
    }
    ++number_of_guesses;
    for (i = 0; i < array_size; ++i) {
      char current_guess_digit = guess[i];
      int guess_as_int = current_guess_digit;

      if (array[i] == current_guess_digit - '0') {
        ++hit;
      } else if (inArray(array, current_guess_digit - '0', array_size)) {
        ++blow;
      }

    }
    printf("%d Hit, %dBlow\n",hit, blow);
    //printf("You input %s\n", guess); 
  }
  printf("Congratulations!!\n");
  printf("You got it right in %d tries.\n", number_of_guesses);

}
