// Chapter 07. 큐 (Queue)
// 07-2. 큐의 연결 리스트 기반 구현

#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
    // Queue 생성 및 초기화
    Queue queue;
    QueueInit(&queue);

    // 데이터 넣기
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);

    // 데이터 꺼내기
    while (!QIsEmpty(&queue))
        printf("%d ", Dequeue(&queue));

    return 0;
}