#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <locale.h>

int main(int argc, char **argv)
{       
        short s = 123;
        char c = 21;
        int i = 1;
        long int li = 123456789012345678L;
        long long int lli = 123456789012345678LL;
        size_t size = sizeof(lli);
        FILE *f;
        int fd;
        char buffer[10] = {0};
        
        /* Basic printf() functionality */
        printf("Short: %hd\n", s);
        printf("Char as single byte integer: %hhd\n", c);
        printf("Integer: %d\n", -32); 
        printf("Unsigned Integer: %u\n", 32); 
        printf("Long Integer: %ld\n", li);
        printf("Long Long Integer: %lld\n", lli);
        printf("Float: %f\n", 3.14159F); 
        printf("Pointer: %p\n", &i);
        printf("Size: %zu\n", size);
        printf("Char: %c\n", 'A'); 
        printf("String: %s\n", "hello world"); 
        printf("Percentage: %%\n");
        printf("Scientific Notation: %e\n", 299792458.0F);
        printf("Placeholder width: $$$%5d$$$\n", 279);
        printf("Placeholder width ignored: $$$%5d$$$\n", 56789901);
        printf("Zero padded placeholder width: $$$%05d$$$\n", 279);
        printf("Sign align: $$$%+d$$$\n", -23);
        printf("Left align: $$$%-5d$$$\n", -23);
        printf("Round float number: %.2f\n", 3.14159F);
        printf("Variable placeholder width: $$$%*d$$$\n", 5, -23);
        printf("Variable placeholder width and round for float: $$$%*.*f$$$\n",
               10, 3, 3.14159F);
        
        setlocale(LC_NUMERIC, "en_US.UTF-8");
        printf("Commas in number for readability: %'d\n", 299792458);
        
        /* fprintf() functionality */
        f = fopen("dummy_01.txt", "w");
        fprintf(f, "%d, %d\n", 3, 2);
        fclose(f);

        /* dprintf() functionality */
        fd = open("dummy_02.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
                perror("open");
                return 1;
        }

        dprintf(fd, "The value of PI is %f\n", 3.14159F);

        close(fd);

        /* 
         * sprintf() and snprintf() functionality 
         * sprintf() doesn't check the buffer size and hence could overflow the
         * buffer and cause stack smashing due to which it is NOT recommended.
         * snprintf() checks the buffer size that has been passed to it as an
         * argument.
         */
        sprintf(buffer, "%d, %d, %s", 2, 3, "hi\n");
        printf("sprintf: %s\n", buffer);
        snprintf(buffer, sizeof(buffer), "%d, %d, %s", 3, 2, 
                 "this would have overflowed the" 
                 "buffer in sprintf()");
        printf("snprintf: %s\n", buffer);

        return 0;
}
