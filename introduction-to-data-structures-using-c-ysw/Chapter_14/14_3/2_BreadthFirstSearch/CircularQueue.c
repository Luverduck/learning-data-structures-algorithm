#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// 큐 초기화
void QueueInit(Queue* pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
};

// 큐가 비어있는지 확인
int QIsEmpty(Queue* pqueue)
{
    // front와 rear가 같을 경우 큐가 비어있다.
    if (pqueue->front == pqueue->rear)
        return TRUE;
    else
        return FALSE;
};

// 다음 삽입 위치
int NextPos(int pos)
{
    // 삽입할 배열의 index
    if(pos == QUEUE_LEN - 1) // 이동한 위치가 배열의 끝일 경우
        return 0;  // 0번째 위치로 이동 (index 순환)
    else    // 그렇지 않을 경우
        return pos + 1; // 다음 위치로 이동
}

// 삽입
void Enqueue(Queue* pqueue, Data data)
{
    // 큐가 가득 차있을 경우 (rear의 다음이 front일 경우)
    if (NextPos(pqueue->rear) == pqueue->front)
    {
        printf("Queue Overflow!\n");
        exit(-1);
    }
    // rear 증가
    pqueue->rear = NextPos(pqueue->rear);
    // 큐의 rear 번째 요소에 data 대입
    pqueue->queueArr[pqueue->rear] = data;
};

// 삭제
Data Dequeue(Queue* pqueue)
{
    // 큐가 비어있을 경우
    if (QIsEmpty(pqueue))
    {
        printf("Queue Underflow!\n");
        exit(-1);
    }
    // front 증가
    pqueue->front = NextPos(pqueue->front);
    // 삭제할 데이터 반환
    return pqueue->queueArr[pqueue->front];
};

// 조회 (front 요소의 값)
Data QPeek(Queue* pqueue)
{
    // 큐가 비어있을 경우
    if (QIsEmpty(pqueue))
    {
        printf("Queue is empty.\n");
        exit(-1);
    }
    // 맨 앞에 저장된 요소의 값 반환
    return pqueue->queueArr[pqueue->front + 1];
};