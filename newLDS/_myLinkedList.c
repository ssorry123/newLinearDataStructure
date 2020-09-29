#pragma once
#include "myLinkedList.h"
#include <stdlib.h>

// print all
// O(n)
void print_linked_list_all(mLL* LL) {
    printf("print linked list\t size : %d\n", LL->size);

    mLLnd* p = LL->begin;
    for (int i = 0; i < LL->size; ++i) {
        printf("[%5d] == %5d\n", i, p->val);
        p = p->next;
    }

    printf("\nprint end\n");
}

// make a node and return pointer, done
mLLnd* _make_mLLnd(item val) {
    mLLnd* ret = (mLLnd*)malloc(sizeof(mLLnd));
    if (ret == NULL) {
        errmsg("fail");
        exit(-1);
    }
    ret->val = val;
    ret->next = NULL;
    ret->prev = NULL;
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


// 리스트에서, 해당 pointer부터 끝까지 삭제
int _del_from_to_NULL(mLLnd* pointer) {
    mLLnd* p = pointer, * tmp = NULL;

    while (p->next != NULL) {
        tmp = p->next;  // tmp에 다음 노드 저장
        free(p);        // 현재 노드 해제
        p = tmp;        // 현재노드를 다음 노드로 변경
    }
    free(p);

    return 0;
}