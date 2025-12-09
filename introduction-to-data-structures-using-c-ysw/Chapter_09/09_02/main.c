// Chapter 09. 우선순위 큐(Priority Queue)와 힙(Heap)
// 09-2. 힙의 구현

#include <stdio.h>
#include "SimpleHeap.h"

int main()
{
    // 힙 생성 및 초기화
    Heap heap;
    HeapInit(&heap);
    // 힙에 데이터 저장
    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    // 힙에서 우선순위가 가장 높은 데이터 출력
    printf("%c\n", HDelete(&heap));
    // 힙에 데이터 저장
    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    // 힙에서 모든 데이터 출력
    while (!HIsEmpty(&heap))
        printf("%c ", HDelete(&heap));

    return 0;
}