#include <stdio.h>

#ifndef CASEONE
#define CASEONE "FIZZ"
#endif

#ifndef CASETWO
#define CASETWO "BUZZ"
#endif
// USAGE
// Define CONSTANTS AT RUN-TIME
// gcc -D 'CASEONE="Ping"' -D 'CASETWO="Pong"'  -o test fizzbuzzv3.c 

int main()
{
    int count;
    
    for (count = 0;count<=25;count++){
        
        // Mutiple of 3 but not a mutiple of 5
        if(count%3==0 && count%5!=0){
            //printf("Fizz -> Value: %d\n",count);
            printf("%s -> Value: %d\n",CASEONE,count);
        }
    
        // Mutiple of 5 but not a mutiple of 3
        else if(count%5==0 && count%3!=0){
            //printf("Buzz -> Value: %d\n",count);
            printf("%s -> Value: %d\n",CASETWO,count);

        }
        
        // Mutiple of 5 and Mutiple of 3
        else if(count%5==0 && count%3==0){
            //printf("Value: %d\n",count);
            printf("FizzBuzz -> Value: %d\n",count);
        }
        else
        {
            printf("Value: %d\n",count);
        }

    }
    
}