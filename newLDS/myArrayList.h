#pragma once
#include "common.h"
/*
Array List
v.0.1
동적할당
*/


typedef myint item; // 모두 같은 자료형을 사용하도록,,


// LinkedList
typedef struct _my_ArrayList {
    int size;       // 유저가 생각하는 공간(참조할 수 있는)
    int capacity;   // 미리 확보해 놓은 공간
    int* arr;
}mAL;


/* define function */

// size크기의 ArrayList 생성,반환
mAL* create_array_list(int size);
// ArrayList 삭제.
int destroy_array_list(mAL* AL);
// 리스트 크기 변경
int rsize_array_list(mAL* AL, int size);


/* manage function */

// 값 바꾸기
int change_array_list(mAL* AL, int idx, item val);
// idx위치에 있는 item 검색,
item search_array_list(mAL* AL, int idx);
// idx위치에, item 삽입, 
int insert_array_list(mAL* AL, int idx, item val);
// idx위치에 있는 item 삭제,
int remove_array_list(mAL* AL, int idx);



/* sub function */
void print_array_list_all(mAL* AL);
int _double_capacity(mAL* AL);