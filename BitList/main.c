#pragma once
#include <stdio.h>
#include "myBitList.h"
#define print_func() printf("test ::%s\n", __FUNCTION__)

void test_create_set_destroy();
void test_set_TRUE();
void test_get();
void test_not();
int main() {

    test_create_set_destroy();
    test_set_TRUE();
    test_get();
    test_not();

    return 0;
}
void test_not() {
    print_func();
    BitList* bl = create_BitList(50, FALSE);

    set_BitList(bl, 5, TRUE);
    set_BitList(bl, 10, TRUE);
    set_BitList(bl, 17, TRUE);
    set_BitList(bl, 30, TRUE);
    set_BitList(bl, 40, TRUE);
    print_BitList(bl, 10);

    not_BitList(bl);
    print_BitList(bl, 10);

    destroy_BitList(bl);
    printf("\n");
    return;
}
void test_get() {
    print_func();

    // create test
    BitList* bl1 = create_BitList(25, FALSE);
    BitList* bl2 = create_BitList(25, TRUE);
    print_BitList(bl1, 5);
    print_BitList(bl2, 5);

    // set
    set_BitList(bl1, 3, TRUE);
    set_BitList(bl1, 12, TRUE);
    set_BitList(bl1, 18, TRUE);
    set_BitList(bl1, 24, TRUE);

    // set
    set_BitList(bl2, 3, FALSE);
    set_BitList(bl2, 12, FALSE);
    set_BitList(bl2, 18, FALSE);
    set_BitList(bl2, 24, FALSE);

    // print
    print_BitList(bl1, 1);
    for (int i = 0; i < bl1->len; ++i) {
        printf("%d ", get_BitList(bl1, i));
    }printf("\n\n");

    print_BitList(bl2, 1);
    for (int i = 0; i < bl2->len; ++i) {
        printf("%d ", get_BitList(bl2, i));
    }

    // destroy
    destroy_BitList(bl1);
    destroy_BitList(bl2);
    printf("\n\n");
}
void test_set_TRUE() {
    print_func();
    // create test
    BitList* bl = create_BitList(50, TRUE);
    print_BitList(bl, 5);

    // set test
    set_BitList(bl, 0, FALSE);
    set_BitList(bl, 3, FALSE);
    set_BitList(bl, 23, FALSE);
    set_BitList(bl, 49, FALSE);
    set_BitList(bl, 5, -3);
    // have to ignore
    set_BitList(bl, -3, FALSE);  // exit
    set_BitList(bl, 50, FALSE);  // exit
    
    print_BitList(bl, 5);

    // destroy
    destroy_BitList(bl);
    printf("\n");
}
void test_create_set_destroy() {
    print_func();
    // create test
    BitList* bl = create_BitList(50, FALSE);
    print_BitList(bl, 5);

    // set test
    set_BitList(bl, 0, TRUE);
    set_BitList(bl, 3, TRUE);
    set_BitList(bl, 23, TRUE);
    set_BitList(bl, 49, TRUE);
    set_BitList(bl, 5, 3);
    // have to ignore
    set_BitList(bl, -3, TRUE); // exit
    set_BitList(bl, 50, TRUE); // exit
    
    // check
    print_BitList(bl, 5);

    printf("%u\n", bl->len);    // 50
    // destroy
    destroy_BitList(bl);
    printf("%u\n", bl->len);    // trash
    printf("\n");
}