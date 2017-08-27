#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "header.h"

int main(){
  char system_input[1000], password[1000];
  int i = 5, j = 0, count = 0;
  char prompt[1000] = "$";
  FILE *fp;

  fp = fopen("secretstring.txt","r");
  if(fp == NULL){  
    exit(1);
  }
  while((fscanf(fp, "%c", password + count)) != EOF){
    count++;
  }
  password[count - 1] = '\0';
  printf("%s\n", password);
  //int k;
  printf("length of password is %ld\n", strlen(password));
  /*for(k = 0; k < 10; k++){
    printf("password[%d] = %c\n", k, password[k]);
  }*/
  //fprintf(stdout, "$ ");
  
  while(1){  
    fprintf(stdout, "%s ", prompt);
    user_input(system_input);
    
    //printf("length of system_input is %ld\n", strlen(system_input));
    if((strlen(system_input) == 1) && (system_input[0] == 'e' || system_input[0] == 'E' || system_input[0] == 'x' || system_input[0] == 'X')){
      exit(1);
    }
    else if(system_input[0] == 'l' && system_input[1] == 'c' && system_input[2] == 'k'){
      //fprintf(stdout, "key to unlock: ");
      char copy[1000], input[1000];
      strcpy(copy, prompt);
      printf("copy: %s\n", copy);
      strcpy(prompt, "key to unlock:\0");
      int num = 1;
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
      printf("%s", prompt);
      printf("123\n");
    }
    
    else if(system_input[5] == 'l'){
     /* if(execlp("ls", "ls", "-l", NULL) == -1){
        fprintf(stdout, "Command not recognized!");
      }*/
      system("ls -l");
    }
  
    else if(system_input[5] == 'c'){
      /*if(execlp("make", "make", NULL) == -1){
        fprintf(stdout, "Command not recognized!");
      }*/
      system("clear");
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
