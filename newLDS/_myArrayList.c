#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>

// just double arr capacity
int _double_capacity(mAL* AL) {
    int capacity = AL->capacity * 2;
    if (capacity > MAXSIZE)
        capacity = MAXSIZE;

    // make new arrlist
    mAL* ret = (mAL*)malloc(sizeof(mAL));
    if (ret == NULL) {
        errmsg("double arr");
        exit(-1);
    }

    // make new arrlist's arr
    ret->arr = (item*)malloc(sizeof(item) * capacity);
    if (ret->arr == NULL) {
        errmsg("double arr 2");
        exit(-1);
    }

    // set return, also copy
    ret->size = AL->size;
    ret->capacity = capacity;
    memset(ret->arr, 0, sizeof(item) * capacity);
    memmove(ret->arr, AL->arr, sizeof(item) * (AL->size));
    
    destroy_array_list(AL);
    AL = ret;
    
    return 0;
}