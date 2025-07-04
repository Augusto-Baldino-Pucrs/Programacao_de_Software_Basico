#include <stdio.h>
#include "Memory.h"
#include "Memory.c"

int main()
{
    memory_t *mem = mymemory_init(1024);

    void *a = mymemory_alloc(mem, 512);
    void *b = mymemory_alloc(mem, 512);

    mymemory_free(mem, b);

    mymemory_display(mem);

    mymemory_stats(mem);

    void *c = mymemory_alloc(mem,128);
        void *d = mymemory_alloc(mem,128);

        void *e = mymemory_alloc(mem,128);
    void *f = mymemory_alloc(mem,128);
    mymemory_stats(mem);

        mymemory_free(mem, c);

            mymemory_free(mem, d);
    mymemory_free(mem, e);
    mymemory_free(mem, f);
    mymemory_stats(mem);

    mymemory_cleanup(mem);
}