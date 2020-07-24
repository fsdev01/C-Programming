/* options.c -- decode command line options */
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEADS		255   /* maximum number of -h options */
typedef short bool;
#define true	1;
#define false	0;
/*
 * usage -- print usage string to the stderr stream and exit
 */
void usage(char * pname) {
    fprintf(stderr, "usage: %s [-a] [-h header] infile outfile\n", pname);
    exit(-1);
}

int main(int argc, char * argv[]) {
    char * infile, * outfile, * pName = *argv;
    char * header_str[MAX_HEADS];
    int i, num_heads = 0;
    char    *s;
    bool append = false; 
    /*
     * decode command line arguments
     */
    while (--argc > 0 && (*++argv)[0] == '-')
        for (s = argv[0] + 1; *s != '\0'; s++)
            switch (*s) {
                case 'a':
                    append = true;
                    break;
                case 'h':
                    if ((header_str[num_heads] = (*++argv)) ==  (char *)NULL)
                        usage(pName);
                    else
                        --argc;
                    if (++num_heads >= MAX_HEADS)
                        fprintf(stderr,"%s: too many headers (max %d)\n",
                                pName, MAX_HEADS);
                    break;
                default:
                    fprintf(stderr,"%s: illegal option %c\n", pName, *s);
                    usage(pName);
                    break;
            }    
    if (argc != 2)
        usage(pName);
    else { 
		/* set infile and outfile to last 2 arguments */
        infile = *argv;
        outfile = *++argv;
    }
	/* now print out options and files entered */
	printf("You entered: %s ", pName);
	if (append) printf("-a ");
	for (i = 0; i < num_heads; ++i)
		printf("-h %s ", header_str[i]);
	printf("%s %s\n", infile, outfile);
	/* ... */
	return 0;
}
