// Chapter 07. 큐 (Queue)
// 07-4. 큐의 활용

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

// 고객의 주문 간격 [초]
#define ORDER_TERM  15

// 햄버거 종류
#define CHE_BUR     0
#define BUL_BUR     1
#define DUB_BUR     2

// 햄버거별 제조 시간 [초]
#define CHE_TERM    12
#define BUL_TERM    15
#define DUB_TERM    24

int main()
{
    // 햄버거별 주문 갯수
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;

    // 주문 처리 완료까지 남은 시간
    int makeProc = 0;

    // 큐 초기화
    Queue queue;
    QueueInit(&queue);
    
    // 난수 생성을 위한 Seed 설정
    srand(time(NULL));

    // 1시간(3600초)동안 진행
    for(int sec = 0; sec < 3600; sec++) // 루프 1회당 1초의 시간이 흐름을 의미
    {
        // 매 15초마다 고객의 주문 접수
        if (sec % ORDER_TERM == 0)
        {
            // rand() % 3의 결과에 따라 주문 결정
            // rand 함수 : 0 ~ RAND_MAX 사이 의사 난수 생성
            switch (rand() % 3) // rand() % 3의 결과는 0, 1, 2 중 하나
            {
                case CHE_BUR :  // 0인 경우
                    Enqueue(&queue, CHE_TERM);
                    cheOrder++;
                    break;
                case BUL_BUR :  // 1인 경우
                    Enqueue(&queue, BUL_TERM);
                    bulOrder++;
                    break;
                case DUB_BUR :  // 2인 경우
                    Enqueue(&queue, DUB_TERM);
                    dubOrder++;
                    break;
            }
        }
        
        // 주문 처리 시간이 0에 도달하면서 큐가 비어있지 않은 경우 (주문 처리가 완료되지 않은 경우)
        if (makeProc <= 0 && !QIsEmpty(&queue))
            // 큐에서 새로운 주문을 꺼내서 주문 처리 시간을 설정한다.
            makeProc = Dequeue(&queue);

        // 주문 처리 시간에서 1초를 감산한다.
        makeProc--;
    }

    // 출력
    printf("Simulation Report!\n");
    printf(" - Cheese Burger : %d\n", cheOrder);
    printf(" - Bulgogi Burger : %d\n", bulOrder);
    printf(" - Double Burger : %d\n", dubOrder);
    printf(" - Waiting Room Size : %d\n", QUEUE_LEN);
}