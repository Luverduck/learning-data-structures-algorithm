#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

// 스택 초기화
void StackInit(Stack* pstack)
{
    // head를 NULL로 초기화
    pstack->head = NULL;
};

// 스택이 비어있는지 확인
int SIsEmpty(Stack* pstack)
{
    // head가 NULL일 경우 (비어있는 경우)
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
};

// 삽입
void SPush(Stack* pstack, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 스택에 생성한 노드 삽입
    newNode->next = pstack->head;
    pstack->head = newNode;
};

// 삭제
Data SPop(Stack* pstack)
{
    // 삭제할 노드와 그 데이터
    Node* rnode;
    Data rdata;
    // 스택이 비어있는 경우
    if (SIsEmpty(pstack))
    {
        printf("Stack Underflow!\n");
        exit(-1);
    }
    // 삭제할 노드와 데이터 지정
    rnode = pstack->head;
    rdata = pstack->head->data;
    // head가 가리키는 노드 변경
    pstack->head = pstack->head->next;
    // 삭제할 노드의 메모리 해제
    free(rnode);
    // 삭제한 노드의 데이터 반환
    return rdata;
};

// 조회 (top 요소의 값)
Data SPeak(Stack* pstack)
{
    // 스택이 비어있는 경우
    if (SIsEmpty(pstack))
    {
        printf("Stack is empty!\n");
        exit(-1);
    }
    // head가 가리키는 노드의 데이터 반환
    return pstack->head->data;
};