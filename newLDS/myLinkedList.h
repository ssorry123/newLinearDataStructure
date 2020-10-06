#pragma once
#include "common.h"
/*
Linked List
v.0.2
양방향
*/


typedef myint item; // 모두 같은 자료형을 사용하도록,,


// LinkedList's Node
typedef struct _my_LinkedList_node {
    item val;	// default 0
    struct _my_LinkedList_node* next;
    struct _my_linkedList_node* prev;
}mLLnd;

// LinkedList
typedef struct _my_LinkedList {
    int size;
    mLLnd* begin;
    mLLnd* end;
}mLL;


/* define function */

// size 크기의 LinkedList 생성,반환
mLL* create_linked_list(int size); 
// LinkedList 삭제
int destroy_linked_list(mLL* LL);


/* manage function */

// 값 바꾸기
int change_linked_list(mLL* LL, int idx, item val);
// idx위치에 있는 item 검색,
item at_linked_list(mLL* LL, int idx);
// idx위치에, item 삽입, 
int insert_linked_list(mLL* LL, int idx, item val);
// 뒤에 붙이기
int append_linked_list(mLL* LL, item val);
// idx위치에 있는 item 삭제,
int remove_linked_list(mLL* LL, int idx);


//// sub function

void print_linked_list_all(FILE *const _Stream, mLL * LL);
mLLnd* _make_mLLnd(item val);
mLLnd* _find_pointer(mLL* LL, int idx);
int _del_from_to_NULL(mLLnd* pointer);

