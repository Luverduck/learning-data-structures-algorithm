#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
// [변경] 이중 연결 리스트 사용을 위한 헤더 추가
#include "DLinkedList.h"

// 테이블 슬롯의 크기
#define MAX_TBL 100

// 해시 함수의 형태 정의
typedef int HashFunc(Key key);

// 테이블의 정의
// [변경] slot의 자료형을 List로 변경
typedef struct _table
{
    List slots[MAX_TBL];
    HashFunc* hashFunc;
} Table;

// 테이블의 초기화
void TBLInit(Table* ptable, HashFunc* pfunc);

// 테이블에 키와 값을 저장
void TBLInsert(Table* ptable, Key key, Value value);

// 키를 이용하여 테이블에서 데이터 탐색
Value TBLSearch(Table* ptable, Key key);

// 키를 이용하여 테이블에서 데이터 삭제
Value TBLDelete(Table* ptable, Key key);

#endif