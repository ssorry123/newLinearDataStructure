#pragma once
#include "myLinkedList.h"
#include <stdlib.h>


item search_linked_list(mLL* LL, int idx) {
    // 일단, 앞에서부터 순차적으로 탐색
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
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


int insert_linked_list(mLL* LL, int idx, item val) {
    // 리스트의 끝 부분에서만 범위를 벗어난 삽입을 할 수 있다
    // 즉, idx==size에 삽입할 수 있다(append)
    if (idx < 0 || idx > LL->size) {
        errmsg("invalid array length");
        exit(-1);
    }
    if (LL->size + 1 > MAXSIZE) {
        errmsg("exceed LIST's MAXSIZE");
        exit(-1);
    }

    mLLnd* tmp = _make_mLLnd(val);	// 새롭게 삽입할 노드
    LL->size++;	// 크기 1 추가

    // 크기를 넘어선 끝에 붙이는 경우
    if (idx == LL->size) {
        LL->end->next = tmp;
        LL->end = tmp;
        return 0;
    }

    // 시작점에 삽입하는 경우
    if (idx == 0) {
        tmp->next = LL->begin;
        LL->begin = tmp;
        return 0;
    }

    // 그 외는 중간
    mLLnd* p = _find_pointer(LL, idx - 1);
    mLLnd* p_next = p->next;	// idx
    p->next = tmp;
    tmp->next = p_next;

    return 0;
}


int remove_linked_list(mLL* LL, int idx) {
    if (idx < 0 || idx >= LL->size) {
        errmsg("invalid array length");
        exit(-1);
    }

    LL->size--;
    // 리스트의 크기가 0이되면, 사라진다..
    if (LL->size == 0) {
        printf("warning!!, linked list destroyed\n");
        free(LL->begin);
        free(LL);
        return 0;
    }

    // 시작
    if (idx == 0) {
        mLLnd* will_del = LL->begin;
        LL->begin = LL->begin->next;
        free(will_del);
        return 0;
    }
    // 끝
    if (idx == LL->size) {
        free(LL->end);
        LL->end = _find_pointer(LL, LL->size - 1);
        LL->end->next = NULL;
        return 0;
    }
    // 중간
    mLLnd* willdel_left = _find_pointer(LL, idx - 1);
    mLLnd* willdel = willdel_left->next;
    willdel_left->next = willdel->next;
    free(willdel);

    return 0;
}

