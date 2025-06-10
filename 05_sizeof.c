#include <stdio.h>

int main(int argc, char **argv) {
        int x = 1;
        int a[] = {1, 2, 3, 4, 5};
        int *ptr_to_array = a;
        printf("\nSize of variable(type)\n");
        printf("%zu\n", sizeof x);

        printf("\nSize of Array(total bytes)\n");
        printf("%zu\n", sizeof a);

        printf("\nLength of Array\n");
        printf("%zu\n", sizeof a / sizeof a[0]);

        printf("\nSize of pointer to array(CAUTION!)\n");
        printf("%zu\n", sizeof ptr_to_array);
        return 0;
}
