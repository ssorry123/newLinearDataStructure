#pragma once
#include <stdint.h>
#include <stdio.h>

// use later
#define TRUE 1
#define FALSE 0

//
#define MAX_BITLIST_LEN 100

//
#define BLOCK_SIZE 32
typedef uint32_t block;

//
typedef struct _BitList {
    size_t len;
    size_t block_arr_size;
    block* block_arr;
}BitList;

// define
BitList* create_BitList(size_t len);
int destroy_BitList(BitList* bl);

// manipulation
int set_BitList(BitList * bl, size_t idx, int val);

// sub func
int print_BitList(BitList* bl, uint32_t jump);