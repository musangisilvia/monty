#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char *path;
	char line[1024] = {0};
	unsigned int line_count = 0;
	FILE *fptr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	path = argv[1];
/* open file */
	fptr = fopen(path, "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
/* GET EACH LINE UNTIL THERE ARE NONE LEFT */
	while(fgets(line, 1024, fptr))
	{
		/* print each line */
		printf("line[%d]: %s\n", ++line_count, line);
	}
	fclose(fptr);
	return (0);
}
