#include <stdio.h>
#include <stdarg.h>

int sum_all(int count, int option, ...) {
        va_list ap;
        va_start(ap, option);
        int sum = 0;
        for (int i = 0; i < count; i++) {
                int x = va_arg(ap, int);
                if (option == 1) {
                        sum += x * x;
                } else {
                        sum += x;
                }
        }
        va_end(ap);
        return sum;
}

int main(int argc, char **argv) {
        printf("Cumulative sum: %d\n", sum_all(4, 0, 1, 2, 3, 4));
        printf("Cumulative sum of squares: %d\n", sum_all(4, 1, 1, 2, 3, 4));
        return 0;
}
