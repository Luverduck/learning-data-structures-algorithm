#include <stdio.h>
#include "UsefulHeap.h"

// 값으로 우선순위를 판단하는 함수
int DataPriorityComp(int n1, int n2)
{
    return n2 - n1; // 오름차순 정렬
}

// 힙 정렬
// - 값이 큰 데이터부터 루트 노드에 차례대로 저장되는 최대 힙을 이용한 정렬
void HeapSort(int arr[], int n, PriorityComp priorityComp)
{
    // 힙 생성 및 초기화
    Heap heap;
    HeapInit(&heap, priorityComp);
    // 힙에 데이터 넣기
    for (int i = 0; i < n; ++i)
        HInsert(&heap, arr[i]);
    // 힙에서 데이터 빼기 및 정렬
    for (int i = 0; i < n; ++i)
        arr[i] = HDelete(&heap);
}

int main()
{
    int arr[] = { 3, 4, 2, 1 };
    
    HeapSort(arr, sizeof(arr) / sizeof(int), DataPriorityComp);

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
        printf("%d ", arr[i]);

    return 0;
}