#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  char *target_string = argv[1];
  char *search_string = argv[2];


  int flag = 0;
  size_t index = 0;
  while(*target_string != '\0') {
    if(strncmp(target_string, search_string, strlen(search_string)) == 0) {
      if (flag != 1) {
        printf("String %s found at the following indices: \n", search_string);
        flag = 1; 
      }
      printf("String found at %u - %u\n", index, index+strlen(search_string)-1);
      index += strlen(search_string);
      target_string += strlen(search_string);
  
    } else {
      ++index;
      ++target_string;
    }  
      
  }
  if (flag != 1) {
    printf("String %s not found. \n", search_string);
  } 
  
}
