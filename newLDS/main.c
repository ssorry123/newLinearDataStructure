#pragma once
#include "common.h"
#include "test.h"

int main1();    // test v.0.2, 2020/09/29

// testing 테스트 중
int main() {



    return 0;
}

// 정확성 테스트, 완료된 것
int main1() {
    // testcase 1 : 생성과 초기화 0 확인, 매모리 해제
    test_create_destroy(100000);
    // 0~499 까지 0~499 할당
    test_seq_change(500);
    // 시작과 중간, 끝에 삽입
    test_insert(300);
    // 항상 시작에 0~299 삽입
    test_insert2(300);
    // 빈 리스트에, 순차적인 숫자 append
    test_append(300);
    // 짝수만 삭제
    test_remove2(300);

    return 0;
}