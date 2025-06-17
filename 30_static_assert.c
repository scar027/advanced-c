#include <stdio.h>

/*
* classical way is:
* #define NUM 2
* #if NUM % 2 == 1
* error "num is NOT even"
* #endif
*/

int main(int argc, char **argv)
{
        constexpr int num = 2;
        /* static_assert available since C23 */
        static_assert(num % 2 == 1, "num is NOT even!");
        return 0;
}
