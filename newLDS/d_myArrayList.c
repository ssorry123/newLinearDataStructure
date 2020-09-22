#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>


mAL* create_array_list(int size) {
    if (size <= 0 || size > MAXSIZE) {
        errmsg("wrong size");
        exit(-1);
    }

    mAL* ret = (mAL*)malloc(sizeof(mAL));
    if (ret == NULL) {
        errmsg("배열리스트 생성1");
        exit(-1);
    }

    // 용량 설정
    int capacity = size * 2;
    if (capacity > MAXSIZE)
        capacity = MAXSIZE;
    ret->size = size;
    ret->capacity = capacity;

    ret->arr = (int*)malloc(sizeof(item) * capacity);
    if (ret->arr == NULL) {
        errmsg("배열리스트 생성2");
        free(ret);
        exit(-1);
    }
    memset(ret->arr, 0, sizeof(item) * capacity);   // 0 초기화


    return ret;
}


int destroy_array_list(mAL* AL) {
    if (AL == NULL) {
        printf("존재하지 않는 연결리스트 삭제 시도");
        exit(-1);
    }

    free(AL->arr);
    free(AL);
    return 0;
}

int rsize_array_list(mAL* AL, int size) {
    // 최대 크기 초과
    if (size > MAXSIZE) {
        errmsg("large Size");
        exit(-1);
    }
    // 크기 변경이 없음
    if (size == AL->size) {
        return 0;
    }
    // 0이하인 경우 파괴시킴
    if (size <= 0) {
        printf("warning!!, Array list destroyed");
        destroy_array_list(AL);
        return 0;
    }

    mAL* ret = create_array_list(size);
    memmove(ret->arr, AL->arr, sizeof(item) * size);
    destroy_array_list(AL);
    AL = ret;

    return 0;
}