#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// 테이블의 초기화
void TBLInit(Table* ptable, HashFunc* pfunc)
{
    // 모든 슬롯의 초기화
    for (int i = 0; i < MAX_TBL; ++i)
        ListInit(&(ptable->slots[i])); // [변경] 리스트의 요소 초기화
    // 해시 함수 등록
    ptable->hashFunc = pfunc;
};

// 테이블에 키와 값을 저장
void TBLInsert(Table* ptable, Key key, Value value)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 슬롯 생성 및 초기화
    Slot nSlot = { key, value };
    // 키 중복 여부 검사
    // - 키는 고유한 값이어야하지만 키에 대한 해시 값은 고유한 값일 필요는 없다. (해시 충돌)
    if (TBLSearch(ptable, key) != NULL) // 이미 해당 키를 가진 데이터가 존재할 경우
    {
        printf("키 중복 오류 발생\n");
        return;
    } 
    else // 그 외
    {
        // 해시값 위치에 저장된 슬롯 리스트에 새로운 슬롯 추가
        LInsert(&(ptable->slots[hashValue]), nSlot);
    }
};

// 키를 이용하여 테이블에서 데이터 탐색
Value TBLSearch(Table* ptable, Key key)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 탐색 과정에서 선택한 슬롯
    Slot cSlot;
    // 해시값을 key로 하는 슬롯에 연결된 리스트에서 첫 번째 요소만 비교
    // - 리스트의 첫 번째 슬롯을 cSlot에 저장하여 반환
    if (LFirst(&(ptable)->slots[hashValue], &cSlot))
    {
        // 테이블에서 데이터 탐색
        if (cSlot.key == key) // 찾으려는 키와 cSlot의 키가 일치할 경우
        {
            return cSlot.value; // cSlot에 저장된 값 반환
        }
        else // 그 외
        {
            // 리스트의 모든 슬롯을 순회한다.
            while (LNext(&(ptable->slots[hashValue]), &cSlot))
            {
                if (cSlot.key == key) // 찾으려는 키와 cSlot의 키가 일치할 경우
                    return cSlot.value; // cSlot에 저장된 값 반환
            }
        }
    }
    // 그 외 경우는 NULL 반환
    return NULL;
};

// 키를 이용하여 테이블에서 데이터 삭제
Value TBLDelete(Table* ptable, Key key)
{
    // 해시값 계산
    int hashValue = ptable->hashFunc(key);
    // 탐색 과정에서 선택한 슬롯
    Slot cSlot;
    // 해시값을 key로 하는 슬롯에 연결된 리스트에서 첫 번째 요소만 비교
    // - 리스트의 첫 번째 슬롯을 cSlot에 저장하여 반환
    if (LFirst(&(ptable->slots[hashValue]), &cSlot))
    {
        // 테이블에서 데이터 탐색
        if (cSlot.key == key) // 찾으려는 키와 cSlot의 키가 일치할 경우
        {
            // 리스트에서 해시값 위치에 저장된 슬롯 삭제
            LRemove(&(ptable->slots[hashValue]));
            // 삭제한 슬롯에 저장된 값 반환
            return cSlot.value;
        }
        else 
        {
            // 리스트의 모든 슬롯을 순회한다.
            while (LNext(&(ptable->slots[hashValue]), &cSlot))
            {
                if (cSlot.key == key) // 찾으려는 키와 cSlot의 키가 일치할 경우
                {
                    // 리스트에서 해시값 위치에 저장된 슬롯 삭제
                    LRemove(&(ptable->slots[hashValue]));
                    // 삭제한 슬롯에 저장된 값 반환
                    return cSlot.value;
                }
            }
        }
    }
    // 그 외 경우는 NULL 반환
    return NULL;
};