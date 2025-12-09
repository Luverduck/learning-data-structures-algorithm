#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

// 힙 기반 우선순위 큐 정의
typedef Heap PQueue;

// 우선순위 큐에 저장할 데이터의 자료형
typedef HData PQData;

// 우선순위 큐 초기화
void PQueueInit(PQueue* ppqueue, PriorityComp comp);

// 우선순위 큐가 비어있는지 확인
int PQIsEmpty(PQueue* ppqueue);

// 우선순위 큐에 데이터 입력
void PEnqueue(PQueue* ppqueue, PQData data);

// 우선순위 큐에서 데이터 출력
PQData PDequeue(PQueue* ppqueue);

#endif