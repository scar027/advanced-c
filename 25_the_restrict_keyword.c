#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void update_pointers(size_t *ptr1, size_t *ptr2, size_t *val)
{
        *ptr1 += *val;
        *ptr2 += *val;
}

void update_pointers_restrict(size_t *restrict ptr1, size_t *restrict ptr2,
                              size_t *restrict val)
{
        *ptr1 += *val;
        *ptr2 += *val;
}

int main(int argc, char **argv)
{
        size_t a;
        size_t b;
        size_t c;

        a = 1;
        b = 2;
        c = 3;
        printf("Initial values: a = %zu, b = %zu, c = %zu\n", a, b, c);

        update_pointers(&a, &b, &c);
        printf("No restrict: a = %zu, b = %zu, c = %zu\n", a, b, c);

        a = 1;
        b = 2;
        c = 3;
        update_pointers_restrict(&a, &b, &c);
        printf("Restrict: a = %zu, b = %zu, c = %zu\n", a, b, c);
        return 0;
}
