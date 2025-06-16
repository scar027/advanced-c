#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        char s[] = "1 2 3 4 5 6";
        char t[] = "1 2 3   4   5   6";
        char *t_ptr;
        char *token;

        /* strtok() - modifies original string and cannot handle empty fields */
        printf("Splitting using strtok(): \n");
        token = strtok(s, " ");
        while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, " ");
        }
        printf("\n");

        /* strsep() - modifies separate string literal and handles empty fields */
        printf("Splitting using strsep(): \n");
        t_ptr = t;
        while ((token = strsep(&t_ptr, " ")) != NULL)
                printf("%s\n", token);
        return 0;
}
