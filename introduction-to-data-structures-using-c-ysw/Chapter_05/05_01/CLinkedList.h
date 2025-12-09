#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

// 연결 리스트에 저장되는 데이터의 자료형
typedef int Data;

// 연결 리스트의 노드 정의
typedef struct _node
{
    Data data;
    struct _node* next;
} Node;

// 원형 연결 리스트 정의
typedef struct _c_linkedList
{
    Node* tail;     // 마지막 노드의 주소
    Node* cur;      // 참조한 노드의 주소
    Node* before;   // 참조한 노드의 바로 앞 노드 주소
    int numOfData;  // 노드의 수
} CLinkedList;

typedef CLinkedList List;

// 초기화
void ListInit(List* plist);

// 삽입
// - 맨 뒤에 삽입
void LInsert(List* plist, Data data);
// - 맨 앞에 삽입
void LInsertFront(List* plist, Data data);

// 조회
// - 첫 번째 노드
int LFirst(List* plist, Data* pdata);
// - 두 번째 이후의 노드
int LNext(List* plist, Data* pdata);

// 삭제
Data LRemove(List* plist);

// 노드의 수 반환
int LCount(List* plist);

#endif