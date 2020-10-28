#pragma once
#include "myBitList.h"
#include <stdio.h>

void errmsg(char* s) {
    if (s != NULL)
        printf("%s error\n", s);
    return;
}

int print_BitList(BitList* bl, uint32_t jump) {
    if (bl == NULL) {
        errmsg("wrong bitlist pointer");
        return FALSE;
    }

    size_t idx = 0;
    for (size_t block_idx = 0; block_idx < bl->block_arr_size; ++block_idx) {
        block mask = 1 << (BLOCK_SIZE - 1);
        block chk_block = bl->block_arr[block_idx];

        while (mask > 0 && idx < bl->len) {
            printf("%u", (mask & chk_block) != 0);
            mask >>= 1;
            ++idx;
            if (idx % jump == 0)
                printf(" ");
        }
    }
    printf("\n");
    return TRUE;
}