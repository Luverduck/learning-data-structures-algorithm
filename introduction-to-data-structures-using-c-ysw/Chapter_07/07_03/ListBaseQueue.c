#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// 큐 초기화
void QueueInit(Queue* pqueue)
{
    pqueue->front = NULL;
    pqueue->rear = NULL;
};

// 큐가 비어있는지 확인
int QIsEmpty(Queue* pqueue)
{
    // front가 NULL일 경우 큐가 비어있다.
    if (pqueue->front == NULL)
        return TRUE;
    else
        return FALSE;
};

// 삽입
void Enqueue(Queue* pqueue, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    // 큐에 노드 추가
    if (pqueue->front == NULL) // 첫 번째 노드 추가
    {
        pqueue->front = newNode;
        pqueue->rear = newNode;
    } 
    else // 두 번째 이후의 노드 추가
    {
        pqueue->rear->next = newNode;
        pqueue->rear = newNode;
    }
};

// 삭제
Data Dequeue(Queue* pqueue)
{
    // 삭제할 노드와 데이터
    Node* rnode;
    Data rdata;
    // 큐가 비어있는 경우
    if (QIsEmpty(pqueue))
    {
        printf("Queue UnderFlow!\n");
        exit(-1);
    }
    // 삭제할 노드와 데이터 지정
    rnode = pqueue->front;
    rdata = pqueue->front->data;
    // front를 현재 front의 다음 노드로 변경
    pqueue->front = pqueue->front->next;
    // 삭제할 노드의 메모리 해제
    free(rnode);
    // 삭제할 노드의 데이터 반환
    return rdata;
};

// 조회 (front 요소의 값)
Data QPeek(Queue* pqueue)
{
    // 큐가 비어있는 경우
    if (QIsEmpty(pqueue))
    {
        printf("Queue is empty.\n");
        exit(-1);
    }
    // front 요소 반환
    return pqueue->front->data;
};