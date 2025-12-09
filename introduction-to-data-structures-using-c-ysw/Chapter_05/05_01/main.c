// Chapter 05. 연결 리스트 (Linked List) 3
// 05-1. 원형 연결 리스트 (Circular Linked List)

#include <stdio.h>
#include "CLinkedList.h"

int main()
{
    // 원형 연결 리스트의 생성 및 초기화
    List list;
    int data;
    int nodeNum;

    ListInit(&list);

    // 리스트에 5개의 데이터 저장
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    // 노드 삭제 전 리스트에 저장된 데이터 출력
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

    // 2의 배수를 모두 찾아서 삭제
    nodeNum = LCount(&list);

    if (nodeNum > 0)
    {
        LFirst(&list, &data);
        if (data % 2 == 0)
            LRemove(&list);

        for (int i = 0; i < LCount(&list); ++i)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
                LRemove(&list);
        }
    }

    // 노드 삭제 후 리스트에 저장된 데이터 출력
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        for (int i = 0; i < LCount(&list) - 1; ++i)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }

    return 0;
}