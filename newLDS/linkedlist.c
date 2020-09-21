#pragma once
#include "linkedlist.h"
#include <stdlib.h>


mLL* create_linked_list() {
	mLL* ret = (mLL*)malloc(sizeof(mLL));
	if (ret == NULL) {
		errmsg("연결리스트 생성1");
		return NULL;
	}

	// begin and end, point same
	// but size==0;
	mLLnd* end_node = (mLLnd*)malloc(sizeof(mLLnd));
	if (end_node == NULL) {
		errmsg("연결리스트 생성2");
		free(ret);
		return NULL;
	}

	// end node have NULL next pointer
	end_node->val = 0;
	end_node->next = NULL;
	// set LinkdList
	ret->size = 0;
	ret->begin = ret->end = end_node;

	return ret;
}


int destroy_linked_list(mLL* LL) {
	// todo
	return 0;
}


item search_linked_list(mLL* LL, int idx) {
	// 일단, 앞에서부터 순차적으로 탐색
	if (idx < 0 || idx >= LL->size) {
		errmsg("연결리스트 인덱스 범위");
		return FAIL;
	}

	mLLnd* here = LL->begin;	// list[0]
	for (int i = 0; i < idx; ++i) {	// O(n), search time
		here = here->next;
	}

	return here->val;
}

int _make_larger_(mLL* LL, int idx) {
	// 연결리스트의 최대 크기보다 큰 인덱스에 삽입하려고 한다면
	if (idx > MAXSIZE - 1) {
		errmsg("cannot make larger the linkedlist");
		return FAIL;
	}

	// todo

	return 0;
}

int insert_linked_list(mLL* LL, int idx, item val) {
	if (val < 0 || idx < 0) {
		errmsg("negative val or idx, when insert");
		return FAIL;
	}
	// 크기를 늘려야 한다면
	if (idx >= LL->size) {
		int ret = _make_larger_(LL, idx);
		if (ret == FAIL) {
			errmsg("fail insert");
			return FAIL;
		}
	}

	// make new Node
	mLLnd* tmp = (mLLnd*)malloc(sizeof(mLLnd));
	if (tmp == NULL) {
		errmsg("삽입 시, 노드 생성 실패");
		return FAIL;
	}
	tmp->val = val;
	++LL->size;

	// insert at begin
	if (idx == 0) {
		// todo


	}
	// insert at end
	// todo

	// insert at middle
	// todo
}


int remove_linked_list(mLL* LL, int idx) {
	// todo
	return 0;
}

