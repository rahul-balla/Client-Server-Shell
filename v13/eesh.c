#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "header.h"
#include <sys/wait.h>

int main(){
  char system_input[1000], password[1000];
  int i = 5, j = 0, count = 0;
  char prompt[1000] = "$";
  FILE *fp;

  fp = fopen("secretstring.txt","r");//reads the secretstring.txt file to get the password
  // the program terminates if there is no such file
  if(fp == NULL){  
    exit(1);
  }
  //scans the password into the variable called "password"
  while((fscanf(fp, "%c", password + count)) != EOF){
    count++;
  }
  password[count - 1] = '\0';
  //printf("%s\n", password);
  //printf("length of password is %ld\n", strlen(password));
  
  // infinite loop for the shell
  // all the commented lines are for debugging purpos
  while(1){  
    fprintf(stdout, "%s ", prompt);
    user_input(system_input);//reads the input entered by the user by each character
    
    //printf("length of system_input is %ld\n", strlen(system_input));

    //condition to exit from the shell
    if((strlen(system_input) == 1) && (system_input[0] == 'e' || system_input[0] == 'E' || system_input[0] == 'x' || system_input[0] == 'X')){
      exit(1);
    }

    // condition to lock the shell
    else if(system_input[0] == 'l' && system_input[1] == 'c' && system_input[2] == 'k'){
      char copy[1000], input[1000];
      int num = 1;
      
      do{
        fprintf(stdout, "key to unclock: ");
        //fgets(input, 10, stdin);
        fscanf(stdin, "%s", input);
        input[10] = '\0';
        num = strcmp(input, password);
      }while(num != 0);
    }
    //condition to list the time stamps of the current directory
    else if(system_input[0] == 'l' && strlen(system_input) == 1){
      system("ls -l");
    }
    // condition to clear the screen
    else if(system_input[0] == 'c' && strlen(system_input) == 1){
      system("clear");
    }
    // condition to change command prompt
    else if (system_input[0] == 'c' && system_input[1] == 'p' && system_input[2] == 'r' && system_input[3] == 't'){
      cprt_func(prompt, system_input);
    }
    // condition implemented when the user enters a command not recognised by the shell
    else if (strlen(system_input) != 0){
       
        int result = CloneRunApp(system_input);
        
        if(result == -1){
          //fprintf(stdout, "A child process could not be created\n");
          exit(1);
        }
        else{
          printf("the process id is: %d\n", result);
        }
    }
  }
}

