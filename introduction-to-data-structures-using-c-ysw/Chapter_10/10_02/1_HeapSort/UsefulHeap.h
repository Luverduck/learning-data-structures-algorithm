#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE        1
#define FALSE       0

// 힙의 배열 길이
#define HEAP_LEN    100

// 힙에 저장할 데이터의 자료형
typedef int HData;

// 힙에 저장할 데이터의 우선순위를 판단하는 함수 포인터
typedef int (*PriorityComp)(HData d1, HData d2);

// 배열 기반 힙 정의
typedef struct _heap
{
    PriorityComp comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

// 힙 초기화
void HeapInit(Heap* pheap, PriorityComp comp);

// 힙이 비어있는지 확인
int HIsEmpty(Heap* pheap);

// 힙에 데이터 입력
void HInsert(Heap* pheap, HData data);

// 힙에서 데이터 출력
HData HDelete(Heap* pheap);

#endif