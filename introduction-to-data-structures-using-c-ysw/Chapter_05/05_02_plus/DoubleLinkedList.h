#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

// 리스트에 저장되는 데이터의 자료형
typedef int Data;

// 리스트의 노드 정의
typedef struct _node
{
    Data data;          // 노드의 데이터
    struct _node* next; // 다음 노드의 주소
    struct _node* prev; // 이전 노드의 주소
} Node;

// 이중 연결 리스트 정의
typedef struct _DLinkedList
{
    Node* head;     // 맨 앞 노드의 주소
    Node* tail;     // 맨 뒤 노드의 주소
    Node* cur;      // 참조한 노드의 주소
    int numOfData;  // 노드의 수
} DLinkedList;

typedef DLinkedList List;

// 초기화
void ListInit(List* plist);

// 삽입
void LInsert(List* plist, Data data);

// 조회
// - 첫 번째 노드
int LFirst(List* plist, Data* pdata);
// - 다음 노드
int LNext(List* plist, Data* pdata);
// - 이전 노드
int LPrev(List* plist, Data* pdata);

// [추가] 삭제
Data LRemove(List* plist);

// 노드의 수 반환
int LCount(List* plist);

#endif