#pragma once
#include "common.h"
#include "test.h"

int main1();

// testing 테스트 중
int main() {
    printf("Hellow world!!!\n");

    main1();
    test_seq_change(500);


    return 0;
}

// 테스트가 잘된 것들 (well done)
int main1() {
    // testcase 1
    test_create_destroy(100000);


    return 0;
}