#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main()
{
    List list;
    Point compPos;
    Point* ppos;

    // 리스트 초기화
    ListInit(&list);

    // 4개의 데이터 저장
    // - Point 변수 4개를 동적 할당 및 초기화 후 리스트에 저장
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);    // [2, 1]
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);    // [2, 2]
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);    // [3, 1]
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);    // [3, 2]
    LInsert(&list, ppos);

    // 리스트에 저장된 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    // xpos가 2인 모든 데이터 삭제
    // 1) 비교할 Point 설정
    compPos.xpos = 2;
    compPos.ypos = 0;
    // 2) list에 저장된 Point와 compPos 비교
    if (LFirst(&list, &ppos))
    {   
        if (PointComp(ppos, &compPos) == 1)     // x값만 같을 경우
        {   
            ppos = LRemove(&list);              // 리스트에서 해당 Point 삭제
            free(ppos);                         // 동적 할당 메모리 해제
        }

        while (LNext(&list, &ppos))
        {
            if (PointComp(ppos, &compPos) == 1) // x값만 같을 경우
            {
                ppos = LRemove(&list);          // 리스트에서 해당 Point 삭제
                free(ppos);                     // 동적 할당 메모리 해제
            }
        }
    }

    // 삭제 후 리스트에 저장된 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    return 0;
}