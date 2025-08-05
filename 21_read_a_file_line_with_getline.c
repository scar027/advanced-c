#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

int main(int argc, char **argv)
{
	FILE *f;
	char *line;
	size_t line_buffer_len;
	ssize_t read_size;

	f = fopen("dummy_03.txt", "r");
	assert(f != NULL);

	line = NULL;
	line_buffer_len = 0;
	read_size = 0;
	while ((read_size = getline(&line, &line_buffer_len, f)) != -1) {
		line[read_size - 1] = '\0';
		printf("Line = %s\n", line);
	}
	assert(feof(f));

	free(line);
	fclose(f);
	return 0;
}
