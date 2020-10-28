#pragma once
#include <stdio.h>
#include "myBitList.h"

void test_create_set_destroy();
int main() {

    test_create_set_destroy();

    return 0;
}
void test_create_set_destroy() {
    // create test
    BitList* bl = create_BitList(50);
    print_BitList(bl, 5);

    // set test
    set_BitList(bl, 0, TRUE);
    set_BitList(bl, 3, TRUE);
    set_BitList(bl, 23, TRUE);
    set_BitList(bl, 49, TRUE);
    // have to ignore
    set_BitList(bl, -3, TRUE);
    set_BitList(bl, 50, TRUE);
    set_BitList(bl, 5, 3);
    // check
    print_BitList(bl, 5);

    printf("%u\n", bl->len);    // 50
    // destroy
    destroy_BitList(bl);
    printf("%u\n", bl->len);    // trash
}