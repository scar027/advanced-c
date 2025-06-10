#include <stdio.h>

int main(int argc, char **argv) {
        /* Use -std=c2x flag while compiling */
        int x = 123'456'789;
        printf("\nThis large number is more readable in code!\n");
        printf("%d\n", x);
        return 0;
}
