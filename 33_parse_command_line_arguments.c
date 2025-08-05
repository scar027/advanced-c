#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int option;
	int i;

	/* try passing flags -a foo -b bar baz qux quux -c to test */
	while ((option = getopt(argc, argv, ":a:b")) != -1) {
		switch (option) {
		case 'a':
			printf("Flag a received: %s\n", optarg);
			break;
		case 'b':
			printf("Flag b received\n");
			break;
		case '?':
			printf("Error\n");
			break;
		case ':':
			printf("Expected arguments\n");
			break;
		}
	}
	for (i = optind; i < argc; i++)
		printf("%d: %s\n", i, argv[i]);
	return 0;
}
