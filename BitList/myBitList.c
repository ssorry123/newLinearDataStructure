#pragma once
#include "myBitList.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>


// make bitlist
BitList* create_BitList(size_t len, int val) {
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
    if (val != TRUE && val != FALSE)
        val = FALSE;

    block tmp;
    if (val == TRUE)
        tmp = ~0;
    else
        tmp = 0;

    memset(ret->block_arr, tmp, (sizeof(block) * ret->block_arr_size));

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
    if (!_check_BitList(bl, idx))
        return FALSE;

    // val to TRUE or FALSE
    if (val <= 0)
        val = FALSE;
    else
        val = TRUE;

    // get block_idx and offset
    size_t block_idx = (size_t)floor(idx / BLOCK_SIZE);
    size_t offset = (size_t)(idx % BLOCK_SIZE);

    block mask = 1 << (BLOCK_SIZE - 1);
    mask >>= offset;

    if (val == TRUE) {
        bl->block_arr[block_idx] |= mask;
    }
    else {
        bl->block_arr[block_idx] &= ~mask;
    }

    return TRUE;
}

int get_BitList(BitList* bl, size_t idx) {
    if (!_check_BitList(bl, idx))
        return FALSE;

    size_t block_idx = (size_t)floor(idx / BLOCK_SIZE);
    size_t offset = (size_t)(idx % BLOCK_SIZE);

    block mask = 1 << (BLOCK_SIZE - 1);
    mask >>= offset;

    if ((bl->block_arr[block_idx] & mask) != 0)
        return TRUE;
    else
        return FALSE;
}

int not_BitList(BitList* bl) {
    if (bl == NULL || bl->block_arr == NULL)
        return FALSE;

    for (int i = 0; i < bl->block_arr_size; ++i) {
        bl->block_arr[i] = ~bl->block_arr[i];
    }

    return TRUE;
}
