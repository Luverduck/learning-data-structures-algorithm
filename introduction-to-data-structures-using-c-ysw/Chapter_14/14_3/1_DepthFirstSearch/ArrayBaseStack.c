#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// 스택 초기화
void StackInit(Stack* pstack)
{
    pstack->topIndex = -1;
};

// 스택이 비어있는지 확인
int SIsEmpty(Stack* pstack)
{
    // topIndex가 -1일 경우 (비어있는 경우)
    if (pstack->topIndex == -1) 
        return TRUE;
    else
        return FALSE;
};

// 삽입
void SPush(Stack* pstack, Data data)
{
    // 스택이 모두 채워져있을 경우
    if (pstack->topIndex >= STACK_LEN - 1) 
    {
        printf("Stack Overflow!\n");
        exit(-1);
    }
    // topIndex 증가
    pstack->topIndex += 1;
    // 스택의 topIndex 위치에 data 추가
    pstack->stackArr[pstack->topIndex] = data;
};

// 삭제
Data SPop(Stack* pstack)
{
    // 삭제할 데이터의 index
    int rIdx;
    // 스택이 비어있을 경우
    if (SIsEmpty(pstack))
    {
        printf("Stack Underflow!\n");
        exit(-1);
    }
    // topIndex를 삭제할 데이터의 index로 설정
    rIdx = pstack->topIndex;
    // topIndex 감소
    pstack->topIndex -= 1;
    // 삭제할 데이터 반환
    return pstack->stackArr[rIdx];
};

// 조회 (top 요소의 값)
Data SPeak(Stack* pstack)
{
    // 스택이 비어있을 경우
    if (SIsEmpty(pstack))
    {
        printf("Stack is empty.\n");
        exit(-1);
    }
    // 스택의 topIndex 요소 반환
    return pstack->stackArr[pstack->topIndex];
};