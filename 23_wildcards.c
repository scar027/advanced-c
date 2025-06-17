#include <stdio.h>
#include <string.h>
#include <fnmatch.h>
#include <glob.h>

int error_function(const char *epath, int errnum)
{
        printf("Error for: %s: %s\n", epath, strerror(errnum));
        /* return 1 if you want to report the error and terminate */
        return 0;
}

int main(int argc, char **argv)
{
        char *s;
        char *t;
        char *u;
        char *v;
        glob_t pglob1;
        glob_t pglob2;
        int res1;
        int res2;
        int res3;
        int res4;
        size_t i;
        
        /* fnmatch */
        s = "hello world";
        res1 = fnmatch("he*wo*", s, 0);
        if (res1 == 0)
                printf("Match!\n");
        else if (res1 == FNM_NOMATCH)
                printf("No match.\n");
        
        t = "hello world";
        res2 = fnmatch("he??? wo*", t, 0);
        if (res2 == 0)
                printf("Match!\n");
        else if (res2 == FNM_NOMATCH)
                printf("No match.\n");

        u = "he32o world";
        res3 = fnmatch("he[a-z][abc]o wo*", u, 0);
        if (res3 == 0)
                printf("Match!\n");
        else if (res3 == FNM_NOMATCH)
                printf("No match.\n");

        v = "path/to/.file";
        res4 = fnmatch("path/*/.file", v, FNM_PATHNAME | FNM_PERIOD);
        if (res4 == 0)
                printf("Match!\n");
        else if (res4 == FNM_NOMATCH)
                printf("No match.\n");

        /* glob */
        printf("Matched files (*.c and *.txt):\n");
        if (glob("*.c", 0, NULL, &pglob1) != 0)
                perror("glob");
        if (glob("*.txt", GLOB_APPEND, NULL, &pglob1) != 0)
                perror("glob");
        for (i = 0; i < pglob1.gl_pathc; i++)
                printf("%zu: %s\n", i, pglob1.gl_pathv[i]);

        /* With error function */
        printf("Matched files (*/*.abc):\n");
        glob("/root/*", 0, error_function, &pglob2);
        for (i = 0; i < pglob2.gl_pathc; i++)
                printf("%zu: %s\n", i, pglob2.gl_pathv[i]);
        
        globfree(&pglob1);
        globfree(&pglob2);
        return 0;
}
