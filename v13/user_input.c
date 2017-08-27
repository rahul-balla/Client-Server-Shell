#include <stdio.h>

void user_input(char *system_input){
  int i = 0;
  char input;

  /**system_input = 'h';
  *(system_input + 1) = 'o';
  *(system_input + 2) = 's';
  *(system_input + 3) = 't';
  *(system_input + 4) = ' ';*/
  
  // reads the input entered by the user
  while((input = getchar()) != '\n'){
    *(system_input + i) = input;
    //printf("system_input[%d] = %c\n", i, input);
    i++;
  }
  // printf("input: %c\n", input);
  *(system_input + i) = '\0';
}
