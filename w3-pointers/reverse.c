// Reverse.c
#define MAX_BUFFER    1024    /* maximum line buffer size */
/*
 * read_line
 * read a line from fp and allocate memory to store
 * removes the '\n' at the end of the line
 */
char * read_line(FILE *fp) {
	char buffer[MAX_BUFFER];
	char c, * line = 0;
	int idx = 0;
	/* read in a line and remove trailing \n */
	while ( idx < MAX_BUFFER - 1 && (c = fgetc(fp)) != EOF && c != '\n' )
		buffer[idx++] = c;
	buffer[idx] = '\0'; /* terminate string */
	/* now allocate space for the line and copy */
	if ( (line = (char *)malloc(sizeof(char) * (strlen(buffer) + 1))) != NULL ) 
		strcpy(line, buffer);
	return line;
}


int main(int argc, char * argv[]) {
	
	FILE * fp;
	char * line;
	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", *argv );
		exit(-1);
	}
	if ( (fp = fopen(argv[1], "r")) == NULL ) {
		fprintf(stderr,"%s: error: can't open %s for reading: ", argv[0], argv[1]);
		perror(0); /* perror prints the system error message */
		exit(-1);
	}
	while (!feof(fp)) {
		line = read_line(fp);	/* read a line */
		print_reverse(line);	/* reverse the line */
		free(line);		/* free the allocated space */
	}
	/* close the file */
	fclose(fp);
}
