#include <stdio.h>

#define STRINGIFY(x, y) printf("%s + %s = %d\n", #x, #y, (x) + (y));
#define PREFIX(var_name) new_##var_name
#define GENERIC_MULTIPLY_FUNC(type)             \
        type multiply_##type(type x, type y)    \
        {                                       \
                return (x) * (y);               \
        }

GENERIC_MULTIPLY_FUNC(float);

int main(int argc, char **argv)
{
        int var1 = 1;
        int var2 = 2;

        STRINGIFY(var1, var2);
        int PREFIX(variable) = 456;
        printf("New variable: %d\n", new_variable);
        printf("Float Multiplication: %.2f\n", multiply_float(3.14159F, 3.14159F));
        return 0;
}
