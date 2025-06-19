??=include <stdio.h>
%:include <stdlib.h>

int main(int argc, char **argv)
??<
        /* 
         * https://en.wikipedia.org/wiki/Digraphs_and_trigraphs_(programming)#C
         * Use -trigraphs flag while compiling
         */
        int a??(??) = ??<1, 2, 3??>;
        int i;
        
        printf("Trigraphs: \n");
        for (i = 0; i < 3; i++)
                printf("a[%d] = %d\n", i, a??(i??));

        printf("Digraphs: \n");
        for (i = 0; i < 3; i++)
                printf("a[%d] = %d\n", i, a<:i:>);
        return 0;
??>
