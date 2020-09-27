#pragma once
#include "test.h"
#include "myLinkedList.h"
#include "myArrayList.h"
#include "common.h"
#include <Windows.h>


void test_create_destroy(int size) {
    printf("start test create and destroy\n");
    Sleep(3000);

    printf("create array list\n");
    mAL* al = create_array_list(size);
    Sleep(3000);

    printf("create linked list\n");
    mLL* ll = create_linked_list(size);
    Sleep(3000);

    // check all zero
    print_array_list_all(al);
    print_linked_list_all(ll);

    // 메모리 감소 확인
    printf("destroy array \n");
    destroy_array_list(al);
    Sleep(3000);

    printf("destroy linked\n");
    destroy_linked_list(ll);
    Sleep(3000);

    // end
    printf("end test create and destroy\n");
    Sleep(3000);
    return;
}

void test_seq_change(int size){
    Sleep(3000);
    // 연결리스트의 경우
    // 해당 idx의 값을 바꿀때, change 함수 사용
    // (v.0.1에서 제공되는 인터페이스만 사용한다)
    printf("create array list\n");
    mAL* al = create_array_list(size);
    Sleep(1000);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);
    Sleep(1000);


    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i);      // fast
        change_linked_list(ll, i, i);   // slow
    }

    print_array_list_all(al);
    print_linked_list_all(ll);

    // 메모리 감소 확인
    printf("destroy array \n");
    destroy_array_list(al);
    Sleep(3000);
    printf("destroy linked\n");
    destroy_linked_list(ll);
    Sleep(3000);

    printf("end test\n");
    Sleep(1000);
}
