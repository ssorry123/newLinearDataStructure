#pragma once
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
        printf("[%5d] == %5d, %5d\n", i, at_array_list(al, i), at_linked_list(ll, i));
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
    append_array_list(al, 444444);
    append_linked_list(ll, 444444);

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
    // 하나라도 존재해야 삽입할 수 있다
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

void test_append(int size) {
    // 빈 리스트 생성
    printf("create array list\n");
    mAL* al = create_array_list(0);
    printf("create linked list\n");
    mLL* ll = create_linked_list(0);

    for (int i = 0; i < size; ++i) {
        append_array_list(al, i+2);
        append_linked_list(ll, i + 2);
    }

    print_array_list_all(al);
    print_linked_list_all(ll);

    destroy_array_list(al);
    destroy_linked_list(ll);

    printf("end test");
}

void test_remove(int size) {
    printf("create array list\n");
    mAL* al = create_array_list(size);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);

    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i + 1);
        change_linked_list(ll, i, i + 1);
    }

    remove_array_list(al, 0);
    remove_array_list(al, (int)(al->size / 2));
    remove_array_list(al, al->size - 2);
    remove_array_list(al, al->size - 1);

    remove_linked_list(ll, 0);
    remove_linked_list(ll, (int)(ll->size / 2));
    remove_linked_list(ll, ll->size - 2);
    remove_linked_list(ll, ll->size - 1);

    print_array_list_all(al);
    print_linked_list_all(ll);

    destroy_array_list(al);
    destroy_linked_list(ll);

    printf("end test");
}

void test_remove2(int size) {
    printf("create array list\n");
    mAL* al = create_array_list(size);
    printf("create linked list\n");
    mLL* ll = create_linked_list(size);

    for (int i = 0; i < size; ++i) {
        change_array_list(al, i, i + 1);
        change_linked_list(ll, i, i + 1);
    }

    for (int i = 0; i < al->size;) {
        if (at_array_list(al, i) % 2 == 0) {
            remove_array_list(al, i);
        }
        else {
            ++i;
        }
    }
    print_array_list_all(al);

    for (int i = 0; i < ll->size;) {
        if (at_linked_list(ll , i) % 2 == 0) {
            remove_linked_list(ll, i);
        }
        else {
            ++i;
        }
    }
    print_linked_list_all(ll);

    destroy_array_list(al);
    destroy_linked_list(ll);

    printf("end test");
}