#include <stdio.h>

void cprt_func(char *string, char* system_input){
  int i = 5; 
  int j = 0;
  
  // reads the string entered by the user after cprt command 
  while(*(system_input + i) != '\0'){
    *(string + j)= *(system_input + i);
    //printf("string[%d] = %c\n", j, *(system_input + i));
    j++;
    i++;
  } 
  string[j] = ':';
  string[j + 1] = '\0';
}
