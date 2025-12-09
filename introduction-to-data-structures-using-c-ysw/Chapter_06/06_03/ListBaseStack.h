#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE        1
#define FALSE       0

// 스택에 저장할 데이터의 자료형
typedef int Data;

// 리스트의 노드 정의
typedef struct _node
{
    Data data;
    struct _node* next;
} Node;

// 연결 리스트 기반 스택의 정의
typedef struct _listStack
{
    Node* head;
} ListStack;

typedef ListStack Stack;

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