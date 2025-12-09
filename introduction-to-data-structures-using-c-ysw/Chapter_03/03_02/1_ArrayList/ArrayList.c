#include <stdio.h>
#include "ArrayList.h"

// 초기화
void ListInit(List* plist)
{
    (plist->numOfData) = 0;     // 저장된 데이터의 수를 0으로 초기화
    (plist->curPosition) = -1;  // 참조한 데이터의 index를 -1로 초기화 (참조하지 않음)
};

// 삽입
void LInsert(List* plist, LData data)
{
    // 리스트에 더 이상 저장할 공간이 없을 경우
    if (plist->numOfData >= LIST_LEN)
    {
        puts("저장이 불가능합니다.\n");
        return;
    }
    // 삽입
    plist->arr[plist->numOfData] = data;    // 리스트에 데이터 저장
    (plist->numOfData)++;                   // 저장된 데이터의 수 증가
};

// 조회
// - 리스트의 첫 번째 데이터
int LFirst(List* plist, LData* pdata)
{
    // 저장된 데이터가 하나도 없을 경우
    if (plist->numOfData == 0) 
        return FALSE;
    // 리스트의 첫 번째 데이터 조회
    (plist->curPosition) = 0;   // 참조한 데이터의 index를 0으로 초기화
    *pdata = plist->arr[0];     // pdata가 가리키는 메모리에 저장
    return TRUE;
};
// - 리스트의 첫 번째 이후 데이터
int LNext(List* plist, LData* pdata)
{
    // 더 이상 참조할 데이터가 없는 경우
    if (plist->curPosition >= (plist->numOfData - 1))
        return FALSE;
    // 리스트의 첫 번째 이후 데이터 조회
    (plist->curPosition)++;     // 참조한 데이터의 index 증가
    *pdata = plist->arr[plist->curPosition];    // pdata가 가리키는 메모리에 저장
    return TRUE;
};

// 삭제
LData LRemove(List* plist)
{
    // 삭제할 데이터의 index
    int rpos = plist->curPosition;

    // 삭제할 데이터 임시 저장
    LData rdata = plist->arr[rpos];

    // 삭제를 위한 데이터 이동
    int len = plist->numOfData;
    for(int i = rpos; i < len; ++i)
        plist->arr[i] = plist->arr[i + 1];

    // 삭제 후 처리
    (plist->numOfData)--;   // 저장된 데이터의 수 감소
    (plist->curPosition)--; // 참조한 데이터의 index 감소

    // 삭제한 데이터 반환
    return rdata;
};

// 리스트에 저장된 데이터의 갯수 반환
int LCount(List* plist)
{
    return plist->numOfData;
};
