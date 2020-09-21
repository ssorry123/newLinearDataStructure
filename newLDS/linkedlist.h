#pragma once
#include "common.h"
/*
단방향
 heap영역에 구현(동적 할당)
 가변 배열
*/

typedef myint item;


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


////// function
// 비어있는 LinkedList 생성,반환. 실패시 NULL 반환
mLL* create_linked_list();
// LinkedList 삭제.성공 0, 실패 -1(FAIL) 반환
int destroy_linked_list(mLL* LL);


// idx위치에 있는 item 검색, 실패시 -1(FAIL) 반환
item search_linked_list(mLL* LL, int idx);
// idx위치에, item 삽입, 성공 0, 실패 -1(FAIL) 반환
int insert_linked_list(mLL* LL, int idx, item val);
// idx위치에 있는 item 삭제, 성공 0, 실패 -1(FAIL) 반환
int remove_linked_list(mLL* LL, int idx);










