#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "header.h"

int main(){
  //pid_t k;
 // char input;
  char system_input[1000];
  char password[1000];
  int i = 5;
  int j = 0;
  int count = 0;
  char prompt[1000] = "$\0";
  FILE *fp;

  fp = fopen("secretstring.txt","r");
  if(fp == NULL){  
    exit(1);
  }
  while((fscanf(fp, "%c", password + count)) != EOF){
    count++;
  }
  password[10] = '\0';
  printf("%s\n", password);
  int k;
  printf("length of password is %d\n", strlen(password));
  for(k = 0; k < 10; k++){
    printf("password[%d] = %c\n", k, password[k]);
  }
  //fprintf(stdout, "$ ");
  while(1){  
    fprintf(stdout, "%s ", prompt);
    user_input(system_input);
    
    //printf("length of system_input is %ld\n", strlen(system_input));
    if((strlen(system_input) == 6) && (system_input[5] == 'e' || system_input[5] == 'E' || system_input[5] == 'x' || system_input[5] == 'X')){
      exit(1);
    }
    else if(system_input[5] == 'l' && system_input[6] == 'c' && system_input[7] == 'k'){
      //fprintf(stdout, "key to unlock: ");
      char copy[1000], input[1000];
      strcpy(copy, prompt);
      strcpy(prompt, "key to unlock:\0");
      int num;
      do{
        fprintf(stdout, "%s ", prompt);
        //fgets(input, 10, stdin);
        fscanf(stdin, "%s", input);
        input[10] = '\0';
        //num = string_compare(input, password);
        /*for(i = 0; i < 10; i++){
          printf("%c %c\n", input[i], password[i]);
         //num = strcmp(input, password);
        }*/
        //printf("123\n");
        num = strcmp(input, password);
        //fprintf(stdout, "the password typed by user is %s\n", input);
        //fprintf(stdout, "The value of comparison is %d\n", num);
      }while(num != 0);
      strcpy(prompt, copy);
    }
    else{
      if(system_input[5] == 'c' && system_input[6] == 'p' && system_input[7] == 'r' && system_input[8] == 't'){
        cprt_func(prompt, system_input);
        //fprintf(stdout, "%s: ", prompt);
      }
      else{
        //system_input[i] = '\0';
        system(system_input);
      }
    }
  }
}
