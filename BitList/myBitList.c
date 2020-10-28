#pragma once
#include "myBitList.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>

// make bitlist
BitList* create_BitList(size_t len) {
    if (len <= 0 || len > MAX_BITLIST_LEN) {
        errmsg("wrong BitList length");
        exit(1);
    }

    // malloc bitlist
    BitList* ret = (BitList*)malloc(sizeof(BitList)); 
    if (ret == NULL) {
        errmsg("malloc1");
        exit(1);
    }

    // set bitlist
    ret->len = len;
    // enough size
    ret->block_arr_size = (size_t)((ret->len / BLOCK_SIZE) + 1);

    // malloc bitlist block
    ret->block_arr = (block*)malloc(sizeof(block) * (ret->block_arr_size));
    if (ret->block_arr == NULL) {
        errmsg("malloc2");
        free(ret);
        exit(1);
    }
    // init block, all zero
    memset(ret->block_arr, 0, (sizeof(block) * ret->block_arr_size));

    return ret;
}

int destroy_BitList(BitList* bl) {
    if (bl == NULL) {
        errmsg("NULL pointer");
        return FALSE;
    }

    // free inner memory
    if (bl->block_arr != NULL)
        free(bl->block_arr);
    // free
    free(bl);
    return TRUE;
}

int set_BitList(BitList* bl, size_t idx, int val) {
    if (bl == NULL || idx < 0 || idx >= bl->len) {
        printf("wrong index\n");
        return FALSE;
    }
    if (val != FALSE && val != TRUE) {
        printf("idx %u, val %d set ignored, val only TRUE or FALSE\n", idx, val);
        return FALSE;
    }

    // get block_idx and offset
    size_t block_idx = (size_t)floor(idx / BLOCK_SIZE);
    size_t offset = (size_t)(idx % BLOCK_SIZE);

    block mask = 1 << (BLOCK_SIZE - 1);
    mask >>= offset;

    bl->block_arr[block_idx] |= mask;
    return TRUE;
}

