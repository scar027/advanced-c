#include <stdio.h>

struct vec2 {
        int x;
        int y;
};

int scaled_sum(int scalar, struct vec2 v)
{
        return scalar * v.x + scalar * v.y;
}

int sum(int a[], int len)
{
        int i;
        int s = 0;
        
        for (i = 0; i < len; i++)
                s += a[i];
        return s;
}
int main(int argc, char **argv) 
{
        struct vec2 v1;
        struct vec2 v2;
        int res1;
        int res2;
        int s;
        int *a;
        int i;
        int n;
        
        /* Usual struct usage */
        v1.x = 4;
        v1.y = 5;
        res1 = scaled_sum(2, v1);
        printf("Regular struct usage: %d\n", res1);

        /* Anonymous struct */
        res2 = scaled_sum(2, (struct vec2){4, 5});
        printf("Anonymous struct: %d\n", res2);

        /* Anonymous array */
        n = 7;
        s = sum((int[]){4, 5, 6, 7, 8, 9, 10}, n);
        printf("Anonymous array: %d\n", s);

        /* Anonymous initialization */
        a = (int []){4, 5, 6, 7, 8, 9, 10};
        printf("Anonymously initialized array: ");
        for (i = 0; i < n; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");

        v2 = (struct vec2){4, 5};
        printf("v2.x: %d\n", v2.x);
        printf("v2.y: %d\n", v2.y);
        return 0;
}
