#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE    1
#define FALSE   0

// 큐에 저장할 데이터의 자료형
typedef int Data;

// 큐에 저장할 노드 정의
typedef struct _node
{
    Data data;
    struct _node* next;
    struct _node* prev;
} Node;

// 이중 연결 리스트 기반 덱의 정의
typedef struct _dlDeque
{
    Node* head;
    Node* tail;
} DLDeque;

typedef DLDeque Deque;

// 덱 초기화
void DequeInit(Deque* pdeque);

// 덱이 비어있는지 확인
int DQIsEmpty(Deque* pdeque);

// 삽입 (머리)
void DQAddFirst(Deque* pdeque, Data data);

// 삽입 (꼬리)
void DQAddLast(Deque* pdeque, Data data);

// 삭제 (머리)
Data DQRemoveFirst(Deque* pdeque);

// 삭제 (꼬리)
Data DQRemoveLast(Deque* pdeque);

// 조회 (머리)
Data DQGetFirst(Deque* pdeque);

// 조회 (꼬리)
Data DQGetLast(Deque* pdeque);

#endif