#pragma once
#include "myLinkedList.h"
#include <stdlib.h>


// make a node and return pointer, done
mLLnd* _make_mLLnd(item val) {
    mLLnd* ret = (mLLnd*)malloc(sizeof(mLLnd));
    if (ret == NULL) {
        errmsg("fail");
        exit(-1);
    }
    ret->val = val;
    ret->next = NULL;
    return ret;
}


// 링크드 리스트에서, idx번째 포인터 반환
mLLnd* _find_pointer(mLL* LL, int idx) {
    mLLnd* here = LL->begin;

    for (int i = 0; i < idx; ++i) {
        here = here->next;
    }

    return here;
}


// 단뱡향 리스트에서, 해당 pointer부터 끝까지 삭제
int _del_from_to_NULL(mLLnd* pointer) {
    mLLnd* p = pointer, * tmp = NULL;

    while (p->next != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(p);

    return 0;
}