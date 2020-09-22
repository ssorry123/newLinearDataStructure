#pragma once
#include "common.h"
/*
Linked List
v.0.1
단방향, 동적할당
*/


typedef myint item; // 모두 같은 자료형을 사용하도록,,


// LinkedList's Node
typedef struct _my_LinkedList_node {
    item val;	// default 0, can only 0 or positive
    struct _my_LinkedList_node * next;
}mLLnd;

// LinkedList
typedef struct _my_LinkedList {
    int size;
    mLLnd* begin;
    mLLnd* end;
}mLL;


/* define function */

// 비어있는 LinkedList 생성,반환
mLL* create_linked_list(int size); 
// LinkedList 삭제.성공
int destroy_linked_list(mLL* LL);
// 리스트 크기 변경
int rsize_linked_list(mLL* LL, int size);


/* manage function */

// 값 바꾸기
int change_linked_list(mLL* LL, int idx, item val);
// idx위치에 있는 item 검색,
item search_linked_list(mLL* LL, int idx);
// idx위치에, item 삽입, 
int insert_linked_list(mLL* LL, int idx, item val);
// idx위치에 있는 item 삭제,
int remove_linked_list(mLL* LL, int idx);


//// sub function

mLLnd* _make_mLLnd(item val);
mLLnd* _find_pointer(mLL* LL, int idx);
int _del_from_to_NULL(mLLnd* pointer);
