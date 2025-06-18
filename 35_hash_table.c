#include <stdio.h>
#include <search.h>
#include <stdint.h>

void print_entry(ENTRY* entry)
{
        if (entry == NULL) {
                printf("NULL\n");
                return;
        }
        printf("%s->%d\n", entry->key, *(int *)entry->data);
}

int main(int argc, char **argv)
{       
        static int v1 = 1;
        static int v2 = 2;
        static int v3 = 3;
        static int v4 = 4;
        ENTRY entries[] = {
                { .key = "foo", .data = &v1 },
                { .key = "bar", .data = &v2 },
                { .key = "baz", .data = &v3 },
                { .key = "qux", .data = &v4 },
        };
        ENTRY *res;
        int i;
        
        hcreate(30);
        for (i = 0; i < 4; i++)
                hsearch(entries[i], ENTER);

        res = hsearch(entries[2], FIND);
        print_entry(res);

        hdestroy();
        return 0;
}
