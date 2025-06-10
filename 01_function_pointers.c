#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int add(int x, int y) {
        return x + y;
}

bool check_odd(int x) {
        return x % 2 == 1;
}

void function_with_function_parameter(int a[10], bool (*condition)(int)) {
        for (int i = 0; i < 10; i++) {
                if (condition(a[i])) {
                        printf("%d\n", a[i]);
                }
        }
}

int custom_compare(const void *x1, const void *x2) {
        return (*(int *)x1 - *(int *)x2);
}

int main(int argc, char **argv) {
        /* Pointer to a function */
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int (*add_function_pointer)(int, int) = add;
        printf("\nExample 1: Function pointer usage\n");
        printf("%d\n", add_function_pointer(5, 6));
        
        /* Passing a function as an argument to function parameter */
        printf("\nExample 2: Function as parameter\n");
        function_with_function_parameter(a, check_odd);

        /* Sorting with a custom comparator */
        printf("\nExample 3: Sorting with custom comparator\n");
        int b[10] = {1, 3, 2, 5, 4, 6, 8, 7, 10, 9};
        printf("Array before sorting: \n");
        for (int i = 0; i < 10; i++) {
                printf("%d ", b[i]);
        }
        printf("\n");
        qsort(b, 10, sizeof(int), custom_compare);
        printf("Array after sorting: \n");
        for (int i = 0; i < 10; i++) {
                printf("%d ", b[i]);
        }
        printf("\n");
        return 0;
}
