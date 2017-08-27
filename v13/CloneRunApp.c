#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

int CloneRunApp(char *binary){
      int i, count;       
      char split_string[100][100];
        char *copy = binary;
        char *split;
        split = strtok(copy, " ");
        count = 0;
        //printf("the system_input is %s\n", system_input); 
        while(split != NULL){
          //(split_string[count]) = (char*)malloc (strlen(split) + 1);
          strcpy(split_string[count],split);
          //printf("%s\n",split);
          //printf("count[%d] = %s\n",count, split_string[count]);
          split = strtok(NULL, " ");
          count++;
        }
        
        char *s[count + 1];

        for(i = 0; i < count; i++){
          s[i] = split_string[i];
          //printf("*s[%d] = %s\n", i, s[i]);
        }
        s[i + 1] = NULL;
      
      //printf("size of s is %ld\n", sizeof(*s));
      int number = 0;
      char *newString[count];// = s[0][0];
      if(s[0][0] == 'd' && s[0][1] == 'd'){
        char* num_char;
        //char *newString[count];

        num_char = (char *) malloc ((strlen(s[0]) - 1)*sizeof(char));

        for(i = 2; i < strlen(s[0]); i++){
          num_char[i - 2] = s[0][i];  
        }
        //printf("num_char is %s\n", num_char);
        number = atoi(num_char);
        //printf("number is %d\n", number);

        for(i = 1; i < count; i++){
          newString[i - 1] = s[i];
          //printf("newString[%d] = %s\n", i-1, newString[i-1]);
        }
      }
 
      pid_t k;
      k = fork();
      int status;
      //fprintf(stdout, "new process will run: %s\n", system_input);
      // when the creation of a child process fails
      if(k < 0){
        fprintf(stdout, "Child process could not be created.\n");
        return -1;
      }
      // when the child process is created
      else if(k == 0){
        if(s[0][0] == 'd' && s[0][1] == 'd'){
          sleep(number);
          if(execvp(newString[0], newString) == -1){
            fprintf(stdout, "The process entered was invalid\n");
            exit(1);
          }
        }
        else{
          if(execvp(s[0], s) == -1){
            fprintf(stdout, "The process entered was invalid\n");
            exit(1);
          }
        }

      }
      // parent process
      else{
      /*To prevent the user from entering the data, I used the time library which measures the current time and delays according to the time entered by the user*/
        if(s[0][0] == 'd' && s[0][1] == 'd'){
            fprintf(stdout, "The program will sleep for %d seconds\n", number);
            clock_t start = clock()/ CLOCKS_PER_SEC;
            clock_t end;

            while(end <= (start + number)){
              end = clock()/ CLOCKS_PER_SEC;  
            }
        }

        return getpid();
        //fprintf(stdout, "The process entered was invalid.\n");
      }
}
