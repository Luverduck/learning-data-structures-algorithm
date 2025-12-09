// Chapter 04. 연결 리스트(Linked List) 2
// 04-3. 연결 리스트의 정렬 삽입 구현

#include <stdio.h>
#include "DLinkedList.h"

// 정렬 함수 (오름차순 정렬, 크기가 작은 데이터가 앞에 위치)
int WhoIsPrecede(int d1, int d2)
{
    if (d1 < d2)
        return 0;   // d1이 앞에 위치한다.
    else
        return 1;   // d2가 앞에 위치한다.
}

int main()
{
// 리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // [추가] 정렬 기준 설정
    SetSortRule(&list, &WhoIsPrecede);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // 숫자 22를 탐색하여 모두 삭제
    if(LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }

    // 삭제 후 리스트에 저장된 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
};