#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{       
        FILE *f;
        char c;

        f = fopen("dummy_03.txt", "r");
        if (f == NULL) {
                printf("Error using errno and strerror(): \n");
                printf("%d: %s\n", errno, strerror(errno));

                printf("Error using perror(): \n");
                perror("fopen");
                return 1;
        }

        while ((c = fgetc(f)) != EOF)
                fputc(c, stdout);
        return 0;
}
