#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

// '참' / '거짓'을 표현하기 위한 매크로
#define TRUE    1
#define FALSE   0

// 연결 리스트에 저장되는 데이터의 자료형 정의
typedef int LData;

// 연결 리스트의 노드 정의
typedef struct _node
{
    LData data;
    struct _node* next;
} Node;

// 연결 리스트의 정의
typedef struct _linkedList
{
    Node* head;     // 더미 노드의 주소
    Node* cur;      // 리스트에서 참조한 데이터의 index
    Node* before;   // 리스트에서 참조 및 삭제할 데이터의 index
    int numOfData;  // 리스트의 노드 수
} LinkedList;

typedef LinkedList List;

// 초기화
void ListInit(List* plist);

// 삽입
void LInsert(List* plist, LData data);

// 조회
// - 리스트의 첫 번째 데이터
int LFirst(List* plist, LData* pdata);
// - 리스트의 첫 번째 이후 데이터
int LNext(List* plist, LData* pdata);

// 삭제
LData LRemove(List* plist);

// 리스트에 저장된 데이터의 갯수 반환
int LCount(List* plist);

#endif