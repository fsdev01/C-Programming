//  task1.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Test with command /bin/ls
int main(int argc,char *argv[])
{
    
    //Input: User string of the program wish to launch
    //MUST END INPUT by PRESSING CTRL-D otherwise \n is included.
    char command[100];
    fgets(command,100,stdin);
    printf("Input is: %s\n",command);

    
    pid_t pid = fork();// Parent fork() a child process.
    int status;
    if( pid == 0) // I am child process
    {
        printf("I am the child. %d \n",getpid());
        char *args[2] = {command,0};
        execv(command,args);
    }
    else if ( pid > 0) // I am the parent process
    {
        printf("I am the parent. %d \n",getpid());
        waitpid(pid,&status,0);

        // WIFEXITED: Evaluates to a non-zero value if status was returned for a child process that terminated normally.
        if(WIFEXITED(status))
        {
            printf("Child returned the value: %d\n", WEXITSTATUS(status));
            printf("Child Process PID:%d is gone!!\n",pid);

        }
        
    }
    else // pid < 0 // Creation of child process failed
    {
        exit(-1);
    }
    
    return 0;
}
