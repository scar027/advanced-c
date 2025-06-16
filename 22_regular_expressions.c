#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <assert.h>

int main(int argc, char **argv)
{       
        regex_t preg1;
        regex_t preg2;
        regex_t preg3;
        int errcode;
        int result1;
        int result2;
        const size_t nmatch = 10;
        const size_t errbuf_size = 129;
        char errbuf[errbuf_size + 2];
        regmatch_t pmatch[nmatch + 1];
        char *s;
        size_t i;

        assert(regcomp(&preg1, "st*", REG_ICASE | REG_EXTENDED) == 0);
        result1 = regexec(&preg1, "sTtt", 0, NULL, 0);
        if (result1 == 0)
                printf("Match!\n");
        else if (result1 == REG_NOMATCH)
                printf("No match.\n");

        /* Groups */
        assert(regcomp(&preg2, "(ab*)(cd*)", REG_EXTENDED) == 0);
        s = "abbcdddd";
        result2 = regexec(&preg2, s, nmatch, pmatch, 0);
        if (result2 == 0) {
                printf("Match!\n");
                for (i = 0; pmatch[i].rm_so != -1 && i < nmatch; i++) {
                        char buf[256] = {0};
                        strncpy(buf, s + pmatch[i].rm_so, pmatch[i].rm_eo 
                                - pmatch[i].rm_so);
                        printf("start %d, end %d: %s\n", pmatch[i].rm_so,
                               pmatch[i].rm_eo, buf);
                }
        } else if (result2 == REG_NOMATCH) {
                printf("No match.\n");
        }
        
        /* regerror() */
        errcode = regcomp(&preg3, "ab***", 0);
        if (errcode != 0) {
                regerror(errcode, &preg3, errbuf, errbuf_size);
                printf("regex error '%s': %s\n", "ab***", errbuf);
        }

        regfree(&preg1);
        regfree(&preg2);
        regfree(&preg3);
        return 0;
}
