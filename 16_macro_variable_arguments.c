#include <stdio.h>

#define PRINTF_LOOP(iterations, ...)               \
	{                                          \
		int i;                             \
                                                   \
		for (i = 0; i < (iterations); i++) \
			printf(__VA_ARGS__);       \
	}

int main(int argc, char **argv)
{
	PRINTF_LOOP(5, "hello %d %s\n", 45, "world");
	return 0;
}
