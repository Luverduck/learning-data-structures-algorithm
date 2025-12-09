#include <stdlib.h>
#include "DoubleLinkedList.h"

// 초기화
void ListInit(List* plist)
{
    // 더미 노드 생성
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));

    // 더미 노드간 연결
    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    // 나머지 멤버 초기화
    plist->cur = NULL;
    plist->numOfData = 0;
};

// 삽입
void LInsert(List* plist, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 리스트의 맨 뒤에 노드 추가
    // - 생성한 노드와 tail이 가리키는 노드의 이전 노드 연결
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;
    // - 생성한 노드와 tail이 가리키는 노드 연결
    newNode->next = plist->tail;
    plist->tail->prev = newNode;
    // 리스트의 노드 수 증가
    (plist->numOfData)++;
};

// 조회
// - 첫 번째 노드
int LFirst(List* plist, Data* pdata)
{
    // head가 가리키는 노드의 다음 노드가 tail이 가리키는 노드일 경우 실패
    if (plist->head->next == plist->tail) return FALSE;
    // cur을 head가 가리키는 노드의 주소로 설정
    plist->cur = plist->head->next;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};
// - 다음 노드
int LNext(List* plist, Data* pdata)
{
    // cur이 가리키는 노드가 tail이 가리키는 노드일 경우 실패
    if (plist->cur->next == plist->tail) return FALSE;
    // cur을 현재 cur이 가리키는 노드의 다음 노드로 변경
    plist->cur = plist->cur->next;
    // 변경한 cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};
// - 이전 노드
int LPrev(List* plist, Data* pdata)
{
    // cur이 가리키는 노드가 head가 가리키는 노드일 경우 실패
    if (plist->cur->prev == plist->head) return FALSE;
    // cur을 현재 cur이 가리키는 노드의 이전 노드로 변경
    plist->cur = plist->cur->prev;
    // 변경한 cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};

// [추가] 삭제
Data LRemove(List* plist)
{
    // cur이 가리키는 노드를 삭제할 노드로 지정
    Node* rpos = plist->cur;
    Data rdata = rpos->data;
    // 삭제할 노드의 양쪽 노드를 서로 연결
    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    // cur의 위치 재조정
    plist->cur = plist->cur->prev;
    // 삭제할 노드의 메모리 해제
    free(rpos);
    // 리스트의 노드 수 감소
    (plist->numOfData)--;
    // 삭제한 노드의 데이터 반환
    return rdata;
};

// 노드의 수 반환
int LCount(List* plist)
{
    return plist->numOfData;
};