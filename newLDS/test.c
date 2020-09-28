#pragma once
#include "test.h"
#include "myLinkedList.h"
#include "myArrayList.h"
#include "common.h"



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

void test_seq_change(int size) {
    // 연결리스트의 경우
    // 해당 idx의 값을 바꿀때, change 함수 사용
    // (v.0.1에서 제공되는 인터페이스만 사용한다)
    printf("create array list\n");
    mAL* al = create_array_list(size);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);

    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i);    // fast
        change_linked_list(ll, i, i);   // slow
    }

    for (int i = 0; i < size; ++i) {
        printf("[%5d] == %5d, %5d\n", i, search_array_list(al, i), search_linked_list(ll, i));
    }

    printf("destroy array \n");
    destroy_array_list(al);
    printf("destroy linked\n");
    destroy_linked_list(ll);

    printf("end test\n");
}

void test_insert(int size) {
    printf("create array list\n");
    mAL* al = create_array_list(size);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);

    printf("init arr[idx] = idx\n");
    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i);    
        change_linked_list(ll, i, i);   
    }

    // append
    insert_array_list(al, size, 444444);
    insert_linked_list(ll, size, 444444);

    // insert middle
    insert_array_list(al, (int)(size / 2), 222222);
    insert_linked_list(ll, (int)(size / 2), 222222);

    // insert begin
    insert_array_list(al, 0, 111111);
    insert_linked_list(ll, 0, 111111);

    print_array_list_all(al);
    print_linked_list_all(ll);

    destroy_array_list(al);
    destroy_linked_list(ll);

    printf("end test");
}

void test_insert2(int size) {
    // v.0.1 크기 0의 생성은 안된다
    printf("create array list\n");
    mAL* al = create_array_list(1);
    printf("create linked list\n");
    mLL* ll = create_linked_list(1);


    for (int i = 0; i < size; ++i) {
        insert_array_list(al, 0, i);
        insert_linked_list(ll, 0, i);
    }
    print_array_list_all(al);
    print_linked_list_all(ll);

    destroy_array_list(al);
    destroy_linked_list(ll);

    printf("end test");
}

void test_rsize(int size) {
    int target_size = size * 2;
    printf("create array list\n");
    mAL* al = create_array_list(size);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);

    printf("init\n");
    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i);
        change_linked_list(ll, i, i);
    }

    printf("double size arr\n");
    int a = rsize_array_list(al, target_size);
    int b = rsize_linked_list(ll, target_size);
    printf("%d %d \n", a, b);

    printf("change all 0\n");
    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, 0);
        change_linked_list(ll, i, 0);
    }

    print_array_list_all(al);
    print_linked_list_all(ll);


    destroy_array_list(al);
    destroy_linked_list(ll);

}