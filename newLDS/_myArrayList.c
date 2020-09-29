#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>

// just double arr capacity
int _double_capacity(mAL* AL) {
    int capacity = AL->capacity * 2;
    if (capacity > MAXSIZE)
        capacity = MAXSIZE;

    // make new arrlist's arr
    item* tmp = (item*)malloc(sizeof(item) * capacity);
    if (tmp == NULL) {
        errmsg("double arr 2");
        exit(-1);
    }

    memset(tmp, 0, sizeof(item) * capacity);
    memmove(tmp, AL->arr, sizeof(item) * AL->size);
    free(AL->arr);
    AL->arr = tmp;
    AL->capacity = capacity;
    return 0;
}

void print_array_list_all(FILE* const _Stream, mAL* AL) {
    fprintf(_Stream, "print array list\t size : %d, capacity : %d\n", AL->size, AL->capacity);

    for (int i = 0; i < AL->size; ++i) {
        fprintf(_Stream, "[%5d] == %5d\n", i, AL->arr[i]);
    }

    fprintf(_Stream, "\nprint end\n");

}