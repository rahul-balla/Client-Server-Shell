#include <stdio.h>
#include <string.h>
int string_compare(char *input, char *password){
  int i;
  for(i = 0; i < strlen(password); i++){
    if(*(input + i) != *(password + i)){
      return -1;
    }
  }
  return 0;
}
