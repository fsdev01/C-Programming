//  task2.c - Test by entering "/bin/ls -alr" with CTRL-D
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
    
    //Input: User string of the program wish to launch
    //MUST END INPUT by PRESSING CTRL-D otherwise \n is included.
    char command[100];
    char *failStatus = fgets(command,100,stdin);
    printf("Input is: %s\n",command);
    // Check whether empty string is provided.
    if(failStatus == NULL)
    {
        fprintf(stderr,"ERROR: Empty string provided\n");
        exit(-1);
    }

    
    //LOOP 1: Count number of arguments
    int arguments = 0; // Count number of Arguments base on # of spaces.
    int i;
    for(i = 0; i < strlen(command);i++)
    {
        if(command[i]==' ')
        {
            arguments++;
        }
    }
    // spaces + 1 = # of Arguments
    arguments = arguments + 1;
    printf("Number of Arguments: %d\n",arguments);
    
    //LOOP 2: Extract the arguments.
    //Separate the output into tokens.
    char *token;
    char delim = ' ';
    char **args;
    int noOfItems = (arguments+1);
    args = (char **)malloc(sizeof(char *)* noOfItems); // +1 for NULL character. - Array of Char Pointers

    // Extract each argument
    for(i = 0 ; i < arguments ; i++)      //while( token != NULL) ALTERNATIVE TO FOR LOOP
    {
        if(i == 0)
        {
            token = strtok(command,&delim);//Space is the token.
        }
        else
        {
            token = strtok(NULL,&delim); // WATCH OUT FOR NULL in strtok(NULL,..)
        }
        args[i] = strdup(token); // Copy the Token into args. - strdup also allocates space.
        
        printf("Token at index %d: %s\n",i,args[i]); // Print token gather previous - loop/inital
    }
    // Add the NULL CHARACTER. as required by char *param[3]={"ls","-alr",0};
    args[noOfItems-1] = (char *) NULL;
    printf("Item: %s\n",args[noOfItems-1]);// last item in array.
    
    
    

    
    pid_t pid = fork();// Parent fork() a child process.
    int status;
    if( pid == 0) // I am child process
    {
        printf("I am the child. %d \n",getpid());
        //char *args[2] = {command,0}; // FOR TASK1
        execv(args[0],args);
    }
    else if ( pid > 0) // I am the parent process
    {
        printf("I am the parent. %d \n",getpid());

        waitpid(-1,&status,0);
        // WIFEXITED evaluates as true, or 0, if the process ended normally with an exit or return call.
        //WEXITSTATUS if a process ended normally you can get the value that was returned with this macro.
        if(WIFEXITED(status))
        {
            //printf("Child returned the value: %d\n", WEXITSTATUS(status));
            printf("Child Process PID:%d is gone!!\n",pid);

        }
    }
    else // pid < 0 // Creation of child process failed
    {
        exit(-1);
    }
    
    // FREE INNER ITEMS FIRST.
    for(i = 0 ; i < noOfItems ; i++)
    {
        free(args[i]);
    }
    free(args); // Free array of char pointers

    
    return 0;
}
