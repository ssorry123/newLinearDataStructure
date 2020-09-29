#pragma once
#include "myLinkedList.h"
#include <stdlib.h>


mLL* create_linked_list(int size) {
    // 크기가 0인 리스트도 생성할 수 있다
    if (size < 0 || size > MAXSIZE) {
        errmsg("wrong size");
        exit(-1);
    }

    mLL* ret = (mLL*)malloc(sizeof(mLL));
    if (ret == NULL) {
        errmsg("making linked list1");
        exit(-1);
    }

    mLLnd* tmp;
    // size+1개의 노드를 만든다
    // 리스트의 end가 가리키는 노드는 사용하지 않는 노드이다
    tmp = _make_mLLnd(0);
    ret->begin = tmp;
    for (int i = 0; i < size; ++i) {
        tmp->next = _make_mLLnd(0);
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    ret->end = tmp;
    ret->size = size;

    return ret;
}


int destroy_linked_list(mLL* LL) {
    if (LL == NULL) {
        printf("LL is NULL");
        exit(-1);
    }

    _del_from_to_NULL(LL->begin);
    free(LL);
    return 0;
}

