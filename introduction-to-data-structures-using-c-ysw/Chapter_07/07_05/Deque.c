#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 덱 초기화
void DequeInit(Deque* pdeque)
{
    pdeque->head = NULL;
    pdeque->tail = NULL;
};

// 덱이 비어있는지 확인
int DQIsEmpty(Deque* pdeque)
{
    // head와 tail이 모두 NULL일 경우 덱이 비어있다.
    if (pdeque->head == NULL && pdeque->tail == NULL)
        return TRUE;
    else
        return FALSE;
};

// 삽입 (머리)
void DQAddFirst(Deque* pdeque, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 생성한 노드를 기존 노드와 연결
    newNode->prev = NULL;
    newNode->next = pdeque->head;
    // 기존 노드를 생성한 노드와 연결
    if (DQIsEmpty(pdeque))  // 덱이 비어있을 경우
        pdeque->tail = newNode;
    else    
        pdeque->head->prev = newNode;
    // head가 가리키는 노드를 생성한 노드로 변경
    pdeque->head = newNode;
};

// 삽입 (꼬리)
void DQAddLast(Deque* pdeque, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 생성한 노드를 기존 노드와 연결
    newNode->prev = pdeque->tail;
    newNode->next = NULL;
    // 기존 노드를 생성한 노드와 연결
    if (DQIsEmpty(pdeque))  // 덱이 비어있을 경우
        pdeque->head = newNode;
    else
        pdeque->tail->next = newNode;
    // tail이 가리키는 노드를 생성한 노드로 변경
    pdeque->tail = newNode;
};

// 삭제 (머리)
Data DQRemoveFirst(Deque* pdeque)
{
    // 삭제할 노드와 그 데이터
    Node* rnode;
    Data rdata;
    // 덱이 비어있을 경우의 처리
    if (DQIsEmpty(pdeque))
    {
        printf("Dequeue Underflow!\n");
        exit(-1);
    }
    // 삭제할 노드와 데이터 지정
    rnode = pdeque->head;
    rdata = pdeque->head->data;
    // head를 삭제할 노드의 다음 노드로 변경
    pdeque->head = pdeque->head->next;
    // 삭제할 노드의 메모리 해제
    free(rnode);
    // 삭제 후 연결 형태 변경
    if (pdeque->head == NULL)   // head가 NULL일 경우
        pdeque->tail = NULL;    // tail을 NULL로 변경 (덱이 비어있다.)
    else
        pdeque->head->prev = NULL; // head의 이전 노드 주소를 NULL로 변경
    // 삭제한 데이터 반환
    return rdata;
};

// 삭제 (꼬리)
Data DQRemoveLast(Deque* pdeque)
{
    // 삭제할 노드와 그 데이터
    Node* rnode;
    Data rdata;
    // 덱이 비어있을 경우의 처리
    if (DQIsEmpty(pdeque))
    {
        printf("Dequeue Underflow!\n");
        exit(-1);
    }
    // 삭제할 노드와 데이터 지정
    rnode = pdeque->tail;
    rdata = pdeque->tail->data;
    // head를 삭제할 노드의 다음 노드로 변경
    pdeque->tail = pdeque->tail->prev;
    // 삭제할 노드의 메모리 해제
    free(rnode);
    // 삭제 후 연결 형태 변경
    if (pdeque->tail == NULL)   // tail이 NULL일 경우
        pdeque->head = NULL;    // head를 NULL로 변경 (덱이 비어있다.)
    else
        pdeque->tail->next = NULL; // tail의 다음 노드 주소를 NULL로 변경
    // 삭제한 데이터 반환
    return rdata;
};

// 조회 (머리)
Data DQGetFirst(Deque* pdeque)
{
    // 덱이 비어있을 경우의 처리
    if (DQIsEmpty(pdeque))
    {
        printf("Dequeue is empty.\n");
        exit(-1);
    }
    // 덱의 머리에 저장된 데이터 반환
    return pdeque->head->data;
};

// 조회 (꼬리)
Data DQGetLast(Deque* pdeque)
{
    // 덱이 비어있을 경우의 처리
    if (DQIsEmpty(pdeque))
    {
        printf("Dequeue is empty.\n");
        exit(-1);
    }
    // 덱의 꼬리에 저장된 데이터 반환
    return pdeque->tail->data;
};