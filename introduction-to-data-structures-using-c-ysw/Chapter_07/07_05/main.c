#include <stdio.h>
#include "Deque.h"

int main()
{
    // Dequeue 생성 및 초기화
    Deque deque;
    DequeInit(&deque);

    // 데이터 넣기
    DQAddFirst(&deque, 3);
    DQAddFirst(&deque, 2);
    DQAddFirst(&deque, 1);

    DQAddLast(&deque, 4);
    DQAddLast(&deque, 5);
    DQAddLast(&deque, 6);

    // 머리에서 꺼내기
    while (!DQIsEmpty(&deque))
        printf("%d ", DQRemoveFirst(&deque));
    printf("\n");

    // 데이터 넣기
    DQAddFirst(&deque, 3);
    DQAddFirst(&deque, 2);
    DQAddFirst(&deque, 1);

    DQAddLast(&deque, 4);
    DQAddLast(&deque, 5);
    DQAddLast(&deque, 6);

    // 꼬리에서 꺼내기
    while (!DQIsEmpty(&deque))
        printf("%d ", DQRemoveLast(&deque));

    return 0;
}