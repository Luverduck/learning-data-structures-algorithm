#include "UsefulHeap.h"
#include <stdlib.h>

// 힙 초기화
void HeapInit(Heap* pheap, PriorityComp comp)
{
    // 우선순위 함수 포인터 초기화
    pheap->comp = comp;
    // 저장된 데이터 수를 0으로 초기화
    pheap->numOfData = 0;
};

// 힙이 비어있는지 확인
int HIsEmpty(Heap* pheap)
{
    // 저장된 데이터의 수가 0이면 힙이 비어있다.
    if (pheap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
};

// 부모 노드의 인덱스 반환
int GetParentIDX(int idx)
{
    // 부모 노드 인덱스 = 현재 노드 인덱스 / 2
    return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 반환
int GetLChildIDX(int idx)
{
    // 왼쪽 자식 노드 인덱스 = 현재 노드 인덱스 * 2
    return idx * 2;
}

// 오른쪽 자식 노드의 인덱스 반환
int GetRChildIDX(int idx)
{
    // 오른쪽 자식 노드 인덱스 = 왼쪽 자식 노드 인덱스 + 1
    return GetLChildIDX(idx) + 1;
}

// 두 자식 노드 중 우선순위가 높은 자식 노드의 인덱스 반환
int GetHiPriChildIDX(Heap* pheap, int idx)
{
    if (GetLChildIDX(idx) > pheap->numOfData) // 자식 노드가 없는 경우
        return 0;
    else if (GetLChildIDX(idx) == pheap->numOfData) // 왼쪽 자식 노드만 있는 경우
        return GetLChildIDX(idx);
    else
    {
        // 두 자식 노드의 우선순위 비교
        if (pheap->comp(pheap->heapArr[GetLChildIDX(idx)], pheap->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

// 힙에 데이터 입력
void HInsert(Heap* pheap, HData data)
{
    // 생성한 노드의 인덱스 초기화 (초기 위치를 마지막 노드로 설정)
    int idx = pheap->numOfData + 1;
    // 루트 노드에 도달할 때까지 반복
    while (idx != 1)
    {
        // 생성한 노드의 우선순위와 부모 노드의 우선순위 비교
        if (pheap->comp(data, pheap->heapArr[GetParentIDX(idx)]) > 0)
        {
            // 생성한 노드와 부모 노드의 위치 교환
            pheap->heapArr[idx] = pheap->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else // 생성한 노드의 우선순위가 낮을 경우
            break; // 위치 탐색 중지
    }
    // 최종적으로 결정된 인덱스에 생성한 노드 저장
    pheap->heapArr[idx] = data;
    // 힙에 저장된 데이터의 갯수 증가
    pheap->numOfData++;
};

// 힙에서 데이터 출력
HData HDelete(Heap* pheap)
{
    // 마지막 노드
    HData lastElement = pheap->heapArr[pheap->numOfData];
    // 반환할 데이터 (루트 노드의 데이터)
    HData rdata = pheap->heapArr[1];
    // 마지막 노드가 삽입될 위치
    int parentIDX = 1; // 마지막 노드의 위치(parentIDX)를 루트 노드 위치(1)로 가정
    int childIDX;
    // 리프 노드에 도달할 때까지 반복 (자식 노드의 인덱스가 NULL일 때까지)
    while (childIDX = GetHiPriChildIDX(pheap, parentIDX)) // childIDX != NULL
    {
        // 루트 노드로 옮긴 마지막 노드가 자식 노드보다 우선순위가 높을 경우
        //if (lastElement.priority <= pheap->heapArr[childIDX].priority)
        if (pheap->comp(lastElement, pheap->heapArr[childIDX]) >= 0)
            break; // 위치 탐색 중지
        // 부모 노드와 자식 노드의 위치 교환
        pheap->heapArr[parentIDX] = pheap->heapArr[childIDX];
        // 부모 노드의 인덱스를 자식 노드의 인덱스로 변경
        parentIDX = childIDX;
    }
    // 최종적으로 결정된 인덱스에 마지막 노드 저장
    pheap->heapArr[parentIDX] = lastElement;
    // 힙에 저장된 데이터의 갯수 감소 (루트 노드를 꺼내기 했으므로)
    pheap->numOfData--;
    // 루트 노드에 있던 데이터 반환
    return rdata;
};