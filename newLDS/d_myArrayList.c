#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>


mAL* create_array_list(int size) {
    // size가 0인 리스트도 생성할 수 있다
    if (size < 0 || size > MAXSIZE) {
        errmsg("wrong size");
        exit(-1);
    }

    mAL* ret = (mAL*)malloc(sizeof(mAL));
    if (ret == NULL) {
        errmsg("making new array list1");
        exit(-1);
    }

    // 용량 설정
    int capacity = (size+1) * 2;
    if (capacity > MAXSIZE)
        capacity = MAXSIZE;

    ret->size = size;
    ret->capacity = capacity;

    ret->arr = (int*)malloc(sizeof(item) * capacity);
    if (ret->arr == NULL) {
        errmsg("making new array list2");
        free(ret);
        exit(-1);
    }
    memset(ret->arr, 0, sizeof(item) * capacity);   // 0 초기화


    return ret;
}


int destroy_array_list(mAL* AL) {
    if (AL == NULL) {
        printf("AL is NULL");
        exit(-1);
    }

    free(AL->arr);
    free(AL);
    return 0;
}
