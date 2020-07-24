// http://www.ontko.com/pub/rayo/cs35/while_getchar.html

// Try: Entering and pressing CRTL-D
// Try: ./countchar < test.txt (redirect text file)
#include <stdio.h>
int main()
{
    int c ;
    int count = 0;
    
    
    // CRTL-D sends EOF signal
    while ( ( c = getchar() ) != EOF ){
        // Number of Characters
        if(c != '\n'){
        	count++;
        }
        
    }
    printf( ": %d characters\n" , count ) ;
}
