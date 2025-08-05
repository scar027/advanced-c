#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *entry;
	struct dirent **entries1;
	struct dirent **entries2;
	int n1;
	int n2;
	int i;

	errno = 0;
	dir = opendir("foo");
	printf("First read:\n");
	while ((entry = readdir(dir)) != NULL)
		printf("%s:\t %d\n", entry->d_name, entry->d_type & DT_DIR);
	assert(errno == 0);

	rewinddir(dir); /* Must be used to re-read dir */

	printf("Second read:\n");
	while ((entry = readdir(dir)) != NULL)
		printf("%s:\t %d\n", entry->d_name, entry->d_type & DT_DIR);
	assert(errno == 0);

	printf("Alphasort: \n");
	n1 = scandir("foo", &entries1, NULL, alphasort);
	for (i = 0; i < n1; i++)
		printf("%d: %s\n", i, entries1[i]->d_name);

	printf("Versionsort: \n");
	n2 = scandir("bar", &entries2, NULL, versionsort);
	for (i = 0; i < n2; i++)
		printf("%d: %s\n", i, entries2[i]->d_name);

	closedir(dir);
	return 0;
}
