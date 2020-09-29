#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int change_array_list(mAL* AL, int idx, item val) {
    if (idx < 0 || idx >= AL->size) {
        errmsg("wrong index");
        printf("idx :: %d, size :: %d ,, in array\n", idx, AL->size);
        exit(-1);
    }
    AL->arr[idx] = val;
    return 0;
}


item at_array_list(mAL* AL, int idx) {
    if (idx < 0 || idx >= AL->size) {
        errmsg("wrong index");
        exit(-1);
    }
    return AL->arr[idx];
}

int append_array_list(mAL* AL, item val) {
    if (AL->size + 1 >= MAXSIZE) {
        errmsg("over size");
        exit(-1);
    }

    if (AL->capacity == AL->size) {
        _double_capacity(AL);
    }

    // 끝에 삽입
    AL->arr[AL->size] = val;
    ++AL->size;

    return 0;
}

int insert_array_list(mAL* AL, int idx, item val) {
    // 존재하는 원소의 위치에 대해서만 삽입할 수 있다
    if (idx < 0 || idx >= AL->size) {
        errmsg("invalid array length");
        printf("idx %d, size %d\n", idx, AL->size);
        exit(-1);
    }
    if (AL->size + 1 > MAXSIZE) {
        errmsg("exceed LIST's MAXSIZE");
        exit(-1);
    }

    // 용량과 크기가 같다면, 용량을 늘려야 한다
    if (AL->capacity == AL->size) {
        _double_capacity(AL);
    }

    // idx부터 모두뒤로 옮기고,, val을 삽입해야 함
    memmove(AL->arr + idx + 1, AL->arr + idx, sizeof(item) * (AL->size - idx));
    AL->arr[idx] = val;
    AL->size++;


    return 0;
}

// idx위치에 있는 item 삭제,
int remove_array_list(mAL* AL, int idx) {
    if (idx < 0 || idx >= AL->size) {
        errmsg("index error");
        exit(-1);
    }
    memmove(AL->arr + idx, AL->arr + (idx + 1), sizeof(item) * (AL->size - (idx + 1)));
    --AL->size;

    return 0;
}