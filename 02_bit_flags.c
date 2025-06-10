#include <stdio.h>
#include <stdbool.h>

typedef enum {
        FLAG_A = (1U << 0),
        FLAG_B = (1U << 1), 
        FLAG_C = (1U << 2),
        FLAG_D = (1U << 3)
} flag_t;

int function_using_bit_flags(int x, flag_t flags) {
        if (flags & FLAG_A) {
                x += 10;
                /* Unset FLAG_D when FLAG_A is used */
                flags &= ~FLAG_D;
        }
        if (flags & FLAG_B) {
                x += 20;
        }
        if (flags & FLAG_C) {
                x += 30;
        }
        if (flags & FLAG_D) {
                x -= 10;
        }
        return x;
}

int main(int argc, char **argv) {
        /* Use the function with no flags set */
        printf("\nExample 1: No flags\n");
        printf("%d\n", function_using_bit_flags(1000, 0));

        /* Use the function with only FLAG_A set */
        printf("\nExample 2: FLAG_A set\n");
        printf("%d\n", function_using_bit_flags(1000, FLAG_A));

        /* Use the function with both FLAG_B & FLAG_C set */
        printf("\nExample 3: FLAG_B & FLAG_C set\n");
        printf("%d\n", function_using_bit_flags(1000, FLAG_B | FLAG_C));

        /* Use the function with FLAG_A, FLAG_C, FLAG_D */
        printf("\nExample 4: FLAG_A & FLAG_B & FLAG_D set\n");
        printf("%d\n", function_using_bit_flags(1000, FLAG_A | FLAG_B | FLAG_D));
        return 0;
}
