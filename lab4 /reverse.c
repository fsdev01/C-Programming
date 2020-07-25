//  task1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *string)
{
    char temp ='a';
    int i;
    for(i=0;i<strlen(string)/2;++i)
    {
        temp = string[i];
        string[i] = string[strlen(string)-1-i];
        string[strlen(string)-1-i] = temp;
    }
    printf("Reverse: %s\n",string);
    
}



int main(int argc,char *argv[]){
    
    if(argc> 1){
        if(strcmp(argv[1],"reverse")==0)
        {
            char input[256];
            //scanf("%s",input); // Only extract 1 line
            fgets(input,sizeof(input),stdin);
            printf("Last character: %c \n",input[strlen(input)-1]);
            reverse(input);
        }
    }
        return 0;
}
