#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE        1
#define FALSE       0
#define STACK_LEN   100

// 스택에 저장할 데이터의 자료형
typedef int Data;

// 배열 기반 스택의 정의
typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];   // 스택의 배열
    int topIndex;               // top 요소의 index
} ArrayStack;

typedef ArrayStack Stack;

// 스택 초기화
void StackInit(Stack* pstack);

// 스택이 비어있는지 확인
int SIsEmpty(Stack* pstack);

// 삽입
void SPush(Stack* pstack, Data data);

// 삭제
Data SPop(Stack* pstack);

// 조회 (top 요소의 값)
Data SPeak(Stack* pstack);

#endif