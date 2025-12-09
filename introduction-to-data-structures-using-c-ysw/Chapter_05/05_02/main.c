// Chapter 05. 연결 리스트 (Linked List) 3
// 05-2. 이중 연결 리스트 (Double Linked List)

#include <stdio.h>
#include "DoubleLinkedList.h"

int main()
{
    // 리스트의 생성 및 초기화
    List list;
    int data;
    int nodeNum;

    ListInit(&list);

    // 리스트에 5개의 데이터 저장
    LInsert(&list, 5);
    LInsert(&list, 4);
    LInsert(&list, 3);
    LInsert(&list, 2);
    LInsert(&list, 1);

    // 리스트에 저장된 데이터 정방향 출력
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        for (int i = 0; i < LCount(&list) - 1; ++i)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n\n");

    // 리스트에 저장된 데이터 역방향 출력
    printf("%d ", list.cur->data);
    if (LPrev(&list, &data))
    {
        printf("%d ", data);
        
        for (int i = 0; i < LCount(&list) - 1; ++i)
        {
            if (LPrev(&list, &data))
                printf("%d ", data);
        }
    }

    return 0;
}