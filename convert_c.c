#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) { 
	if (argc != 2) {
		fputs("Usage: convert <filename>\n", stderr);
		return EXIT_FAILURE;
	}

	FILE *in = fopen(argv[1], "r");
	if (in == NULL) {
		fputs("Unable to open input file", stderr);
		return EXIT_FAILURE;
	}
	char *out_name;
	size_t out_len = strlen(argv[1]) + 5;
	if ((out_name = malloc(out_len)) == NULL) {
		fputs("unable to allocate memory\n", stderr);
		return EXIT_FAILURE;
	}
	strcpy(out_name, argv[1]);
	strcat(out_name, ".out");

	FILE *out = fopen(out_name, "w");
	if (out == NULL) {
		fputs("Unable to open output file", stderr);
		return EXIT_FAILURE;
	}

	clock_t start = clock();

	int ch;
	while (EOF != (ch = fgetc(in)))
	{
		fputc(ch, out);
		if (ch == ',')
			fputc('\n', out);
	}
	clock_t finish = clock();

	printf ("Time: %f\n", (finish-start) / (double)CLOCKS_PER_SEC);
}