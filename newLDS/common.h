#pragma once
#include <stdint.h>
#include <stdio.h>
// 모든 모듈에 공통적으로 사용되는 상수나 자료형, 헤더파일, 함수를 선언합니다.

// #define MAXSIZE 200000000	// 2억
#define MAXSIZE 1000000        // 100만
// 데이터 영역(전역변수)에서 배열의 크기는 10억byte = 1GB를 넘길 수 없음
// MAXSIZE가 2억이고, 4byte int 배열 하나 선언한다면? 8억byte 약 800MB 사용


// use only for item
typedef int32_t myint;

// print error message
void errmsg(char* str);