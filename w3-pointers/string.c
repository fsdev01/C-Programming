#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	// String - An array of characters teminated by \0 null character
	char *name1 = "Alice";
	char name2[] = "Bob";

	// Slow way of printing text - traversing array
	while(*name1){
		putc(*name1++,stdout);
	}

	printf("\n");

	// Fast way of printing text/string
	printf("%s\n",name2);

	printf("\n");

	// Length of string (excluding of \0)
	printf("Length of 'Bob' String: %lu\n",strlen(name2));


	return 0;
}