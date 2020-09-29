#pragma once
#include "myLinkedList.h"
#include <stdlib.h>


item at_linked_list(mLL* LL, int idx) {
    // 일단, 앞에서부터 순차적으로 탐색
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
        printf("idx :: %d, size :: %d ,, in linked\n", idx, LL->size);
        exit(-1);
    }

    return _find_pointer(LL, idx)->val;
}


int change_linked_list(mLL* LL, int idx, item val) {
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
        exit(-1);
    }
    _find_pointer(LL, idx)->val = val;
    return 0;
}

int append_linked_list(mLL* LL, item val) {
    if (LL->size + 1 > MAXSIZE) {
        errmsg("exceed List's MAxSIZE");
        exit(-1);
    }
    LL->end->val = val;
    LL->end->next = _make_mLLnd(0);
    LL->end->next->prev = LL->end;
    LL->end = LL->end->next;

    ++LL->size;
    return 0;
}

int insert_linked_list(mLL* LL, int idx, item val) {
    // 존재하는 원소의 위치에 대해서만 삽입할 수 있다
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
        printf("idx %d, size %d\n", idx, LL->size);
        exit(-1);
    }
    if (LL->size + 1 > MAXSIZE) {
        errmsg("exceed LIST's MAXSIZE");
        exit(-1);
    }

    mLLnd* tmp = _make_mLLnd(val);	// 새롭게 삽입할 노드
    LL->size++;	// 크기 1 추가


    // 시작점에 삽입하는 경우
    if (idx == 0) {
        tmp->next = LL->begin;
        LL->begin->prev = tmp;
        LL->begin = tmp;
        return 0;
    }

    mLLnd* left_pointer = _find_pointer(LL, idx - 1);
    mLLnd* right_pointer = left_pointer->next;
    left_pointer->next = tmp;
    right_pointer->prev = tmp;
    tmp->next = right_pointer;
    tmp->prev = left_pointer;

    return 0;
}


int remove_linked_list(mLL* LL, int idx) {
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
        exit(-1);
    }

    // 사이즈 미리 줄이기
    LL->size--;

    // 시작 위치 삭제
    if (idx == 0) {
        mLLnd* will_del = LL->begin;
        LL->begin = will_del->next;
        LL->begin->prev = NULL;
        free(will_del);
        return 0;
    }
    // 끝
    if (idx == LL->size) {
        LL->end = LL->end->prev;
        free(LL->end->next);
        LL->end->val = 0;
        LL->end->next = NULL;

        return 0;
    }
    // 중간
    mLLnd* willdel = _find_pointer(LL, idx);
    mLLnd* left, * right;
    left = willdel->prev;
    right = willdel->next;
    left->next = right;
    right->prev = left;
    free(willdel);

    return 0;
}

