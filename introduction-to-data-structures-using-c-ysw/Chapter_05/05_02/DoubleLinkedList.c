#include <stdlib.h>
#include "DoubleLinkedList.h"

// 초기화
void ListInit(List* plist)
{
    plist->head = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
};

// 삽입
void LInsert(List* plist, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 리스트에 노드 추가
    // 1) 추가할 노드의 다음 노드를 현재 head가 가리키는 노드로 설정
    newNode->next = plist->head;
    if (plist->head != NULL)            // head가 NULL일 경우 (첫 번째 노드 추가)
        plist->head->prev = newNode;    // head를 추가한 노드의 주소로 설정 (이중 연결)
    // 2) 추가할 노드의 이전 노드를 NULL로 설정
    newNode->prev = NULL;
    // head가 가리키는 노드를 새로 추가된 노드로 설정
    plist->head = newNode;
    // 리스트의 노드 수 증가
    (plist->numOfData)++;
};

// 조회
// - 첫 번째 노드
int LFirst(List* plist, Data* pdata)
{
    // 맨 처음의 노드가 없을 경우 실패
    if (plist->head == NULL) return FALSE;
    // cur을 head가 가리키는 노드의 주소로 설정
    plist->cur = plist->head;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};
// - 다음 노드
int LNext(List* plist, Data* pdata)
{
    // cur이 가리키는 노드의 다음 노드가 없을 경우 실패
    if (plist->cur->next == NULL) return FALSE;
    // cur을 다음 노드의 위치로 설정
    plist->cur = plist->cur->next;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};
// - 이전 노드
int LPrev(List* plist, Data* pdata)
{
    // cur이 가리키는 노드의 이전 노드가 없을 경우 실패
    if (plist->cur->prev == NULL) return FALSE;
    // cur을 이전 노드의 위치로 설정
    plist->cur = plist->cur->prev;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};

// 노드의 수 반환
int LCount(List* plist)
{
    return plist->numOfData;
};