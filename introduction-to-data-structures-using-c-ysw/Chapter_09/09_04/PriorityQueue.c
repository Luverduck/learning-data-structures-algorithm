#include "PriorityQueue.h"
#include "UsefulHeap.h"

// 우선순위 큐 초기화
void PQueueInit(PQueue* ppqueue, PriorityComp comp)
{
    HeapInit(ppqueue, comp);
};

// 우선순위 큐가 비어있는지 확인
int PQIsEmpty(PQueue* ppqueue)
{
    return HIsEmpty(ppqueue);
};

// 우선순위 큐에 데이터 입력
void PEnqueue(PQueue* ppqueue, PQData data)
{
    HInsert(ppqueue, data);
};

// 우선순위 큐에서 데이터 출력
PQData PDequeue(PQueue* ppqueue)
{
    return HDelete(ppqueue);
};