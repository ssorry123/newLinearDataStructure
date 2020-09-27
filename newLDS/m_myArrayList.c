#pragma once
#include "myArrayList.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int change_array_list(mAL* AL, int idx, item val) {
    if (idx < 0 || idx >= AL->size) {
        errmsg("wrong index");
        exit(-1);
    }
    AL->arr[idx] = val;
    return 0;
}


item search_array_list(mAL* AL, int idx) {
    if (idx < 0 || idx >= AL->size) {
        errmsg("wrong index");
        exit(-1);
    }
    return AL->arr[idx];
}


int insert_array_list(mAL* AL, int idx, item val) {
    // 배열의 끝 부분에서만 범위를 벗어난 삽입을 할 수 있다
    if (idx < 0 || idx > AL->size) {
        errmsg("invalid array length");
        exit(-1);
    }
    if (AL->size + 1 > MAXSIZE) {
        errmsg("exceed LIST's MAXSIZE");
        exit(-1);
    }

    // 리스트의 크기가 1 커지는데, 용량이 크기와 같은 경우
    if (AL->capacity == AL->size) {
        _double_capacity(AL);
    }

    // append
    if (idx == AL->size) {
        AL->arr[idx] = val;
        AL->size++;
        return 0;
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

    if (AL->size == 1) {
        printf("warning, array list destroyted");
        destroy_array_list(AL);
        return 0;
    }

    memmove(AL->arr + idx, AL->arr + idx + 1, sizeof(item) * (AL->size - (idx + 1)));
    --AL->size;

    return 0;
}