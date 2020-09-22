#pragma once
#include "myLinkedList.h"
#include <stdlib.h>


mLL* create_linked_list(int size) {
    if (size <= 0 || size > MAXSIZE) {
        errmsg("wrong size");
        exit(-1);
    }

    mLL* ret = (mLL*)malloc(sizeof(mLL));
    if (ret == NULL) {
        errmsg("연결리스트 생성1");
        exit(-1);
    }

    item init_item = 0;

    mLLnd* left, * tmp, * right;
    left = right = _make_mLLnd(init_item);
    for (int i = 1; i < size; ++i) {
        tmp = _make_mLLnd(init_item);
        right->next = tmp;
        right = tmp;
    }

    ret->begin = left;
    ret->end = right;
    ret->size = size;

    return ret;
}


int destroy_linked_list(mLL* LL) {
    _del_from_to_NULL(LL->begin);
    free(LL);
    return 0;
}


int rsize_linked_list(mLL* LL, int size) {
    // 최대 크기 초과
    if (size > MAXSIZE) {
        errmsg("large Size");
        exit(-1);
    }
    // 크기 변경이 없음
    if (size == LL->size) {
        return 0;
    }
    // 0이하인 경우 파괴시킴
    if (size <= 0) {
        printf("warning!!, linked list destroyed");
        destroy_linked_list(LL);
        return 0;
    }

    // 크기를 줄이는 경우, 해당 크기 이후는 파괴시킨다
    if (size < LL->size) {
        LL->end = _find_pointer(LL, size - 1);	// end 포인터 변경
        _del_from_to_NULL(LL->end->next);	// end의 next부터 모두 삭제
        LL->end = NULL;							// end->next 변경
        LL->size = size;
        return 0;
    }

    if (size > LL->size) {
        int inc = LL->size - size;
        mLLnd* tmp;
        for (int i = 0; i < inc; ++i) {
            tmp = _make_mLLnd(0);
            LL->end->next = tmp;
            LL->end = tmp;
            ++LL->size;
        }
        return 0;
    }

    errmsg("no matched situation");
    exit(-1);
}
