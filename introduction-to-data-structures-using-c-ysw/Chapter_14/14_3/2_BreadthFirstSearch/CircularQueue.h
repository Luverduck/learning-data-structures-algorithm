#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE        1
#define FALSE       0

// 배열의 길이
#define QUEUE_LEN   100

// 큐에 저장할 데이터의 자료형
typedef int Data;

// 배열 기반 큐의 정의
typedef struct _cQueue
{
    int front;
    int rear;
    int queueArr[QUEUE_LEN];
} CQueue;

typedef CQueue Queue;

// 큐 초기화
void QueueInit(Queue* pqueue);

// 큐가 비어있는지 확인
int QIsEmpty(Queue* pqueue);

// 삽입
void Enqueue(Queue* pqueue, Data data);

// 삭제
Data Dequeue(Queue* pqueue);

// 조회 (front 요소의 값)
Data QPeek(Queue* pqueue);

#endif