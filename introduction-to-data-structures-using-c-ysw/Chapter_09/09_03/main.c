// Chapter 09. 우선순위 큐(Priority Queue)와 힙(Heap)
// 09-3. 힙의 구현 (개선)

#include <stdio.h>
#include "UsefulHeap.h"

// 우선순위 비교 함수
int DataPriorityComp(char c1, char c2)
{
    return c2 - c1;
}

int main()
{
    // 힙 생성 및 초기화
    Heap heap;
    HeapInit(&heap, DataPriorityComp); // 우선순위 비교 함수 설정
    
    // 힙에 데이터 저장
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    // 힙에서 우선순위가 가장 높은 데이터 출력
    printf("%c\n", HDelete(&heap));
    // 힙에 데이터 저장
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    // 힙에서 모든 데이터 출력
    while (!HIsEmpty(&heap))
        printf("%c ", HDelete(&heap));

    return 0;
}