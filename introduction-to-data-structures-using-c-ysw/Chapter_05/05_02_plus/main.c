// Chapter 05. 연결 리스트 (Linked List) 3
// 05-2. 이중 연결 리스트 (Double Linked List)

#include <stdio.h>
#include "DoubleLinkedList.h"

int main()
{
    // 리스트의 생성 및 초기화
    List list;
    int data;

    ListInit(&list);

    // 리스트에 5개의 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);

    // 삭제 전 리스트에 저장된 데이터 출력
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);

        printf("\n\n");
    }

    // 2의 배수를 모두 찾아서 삭제
    if (LFirst(&list, &data))
    {
        if (data % 2 == 0)
            LRemove(&list);
        
        while (LNext(&list, &data))
        {
            if (data % 2 == 0)
                LRemove(&list);
        }
    }

    // 삭제 후 리스트에 저장된 데이터를 역순으로 출력
    printf("%d ", list.cur->data);
    while (LPrev(&list, &data))
        printf("%d ", data);

    return 0;
}