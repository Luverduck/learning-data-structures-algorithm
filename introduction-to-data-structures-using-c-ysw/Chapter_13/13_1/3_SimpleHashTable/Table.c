#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// 테이블의 초기화
void TBLInit(Table* ptable, HashFunc* pfunc)
{
    // 모든 슬롯의 상태를 '비어있음'으로 초기화
    for (int i = 0; i < MAX_TBL; ++i)
        (ptable->slots[i]).status = EMPTY;
    // 해시 함수 등록
    ptable->hashFunc = pfunc;
};

// 테이블에 키와 값을 저장
void TBLInsert(Table* ptable, Key key, Value value)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 해시값을 인덱스로 하여 테이블에 데이터 저장
    ptable->slots[hashValue].key = key;
    ptable->slots[hashValue].value = value;
    ptable->slots[hashValue].status = INUSE;
};

// 키를 이용하여 테이블에서 데이터 탐색
Value TBLSearch(Table* ptable, Key key)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 해시값을 인덱스로 하여 테이블에서 데이터 탐색
    if (ptable->slots[hashValue].status != INUSE)
        return NULL;
    else 
        return ptable->slots[hashValue].value;
};

// 키를 이용하여 테이블에서 데이터 삭제
Value TBLDelete(Table* ptable, Key key)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 해시값을 인덱스로 하여 테이블에서 데이터 삭제
    if (ptable->slots[hashValue].status != INUSE) // 해당 슬롯의 상태가 '사용 중'이 아닐 경우
    {
        return NULL; // 삭제할 값이 없음
    }
    else // 그 외
    {
        // 슬롯의 상태를 '삭제됨'으로 변경
        (ptable->slots[hashValue]).status = DELETE;
        // 슬롯의 값을 반환
        return (ptable->slots[hashValue]).value;
    }
};