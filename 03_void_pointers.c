#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void *memset_function(void *data, uint8_t c, size_t n) {
        uint8_t *data_as_bytes = (uint8_t *)data;
        for (size_t i = 0; i < n; i++) {
                data_as_bytes[i] = c;
        }
        return data;
}

void map(void *a, size_t n, size_t size, void (*function)(void *)) {
        uint8_t *a_as_bytes = (uint8_t *)a;
        for (size_t i = 0; i < n; i++) {
                function(&a_as_bytes[i * size]);
        }
}

void square(void *x) {
        int *p = x;
        *p = *p * *p;
}

int main(int argc, char **argv) {
        int a[5] = {1, 2, 3, 4, 5};
        printf("\nExample array\n");
        for (int i = 0; i < 5; i++) {
                printf("%d ", a[i]); 
        }
        printf("\n");

        /* Square every element of a */
        map(a, 5, sizeof(int), square);
        printf("\nSquaring elements of the array\n");
        for (int i = 0; i < 5; i++) {
                printf("%d ", a[i]); 
        }
        printf("\n");
 
        /* Set all bytes in concerned memory to -1 */
        memset_function(a, -1, sizeof(a));
        printf("\nArray after applying memset\n");
        for (int i = 0; i < 5; i++) {
                printf("%d ", a[i]); 
        }
        printf("\n");
        return 0;
}
