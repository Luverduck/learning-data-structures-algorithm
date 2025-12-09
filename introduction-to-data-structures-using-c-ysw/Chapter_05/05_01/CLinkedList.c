#include <stdlib.h>
#include "CLinkedList.h"

// 초기화
void ListInit(List* plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
};

// 삽입
// - 맨 뒤에 삽입
void LInsert(List* plist, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 리스트에 노드 추가
    if (plist->tail == NULL)    // 첫 번째 노드 추가
    {
        // 생성한 노드를 tail로 설정
        plist->tail = newNode;
        // 생성한 노드의 다음 노드를 자기 자신으로 설정
        newNode->next = newNode;
    }
    else                        // 두 번째 이후의 노드 추가
    {
        // 1) 생성한 노드의 다음 노드를 리스트의 마지막 노드의 다음 노드(첫 번째 노드)로 설정
        newNode->next = plist->tail->next;
        // 2) 리스트의 마지막 노드의 다음 노드를 생성한 노드로 설정
        plist->tail->next = newNode;
        // 3) 리스트의 마지막 노드를 생성한 노드로 설정
        plist->tail = newNode;
    }
    // 리스트의 노드 수 증가
    (plist->numOfData)++;
};
// - 맨 앞에 삽입
void LInsertFront(List* plist, Data data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 리스트에 노드 추가
    if (plist->tail == NULL)    // 첫 번째 노드 추가
    {
        // 생성한 노드를 tail로 설정
        plist->tail = newNode;
        // 생성한 노드의 다음 노드를 자기 자신으로 설정
        newNode->next = newNode;
    }
    else                        // 두 번째 이후의 노드 추가
    {
        // 1) 생성한 노드의 다음 노드를 리스트의 마지막 노드의 다음 노드(첫 번째 노드)로 설정
        newNode->next = plist->tail->next;
        // 2) 리스트의 마지막 노드의 다음 노드를 생성한 노드로 설정
        plist->tail->next = newNode;
    }
    // 리스트의 노드 수 증가
    (plist->numOfData)++;
};

// 조회 (리스트의 노드를 조회하여 pdata가 가리키는 메모리에 저장)
// - 첫 번째 노드
int LFirst(List* plist, Data* pdata)
{
    // 저장된 노드가 없을 경우 실패
    if (plist->tail == NULL) return FALSE;
    // before를 리스트이 마지막 노드로 설정
    plist->before = plist->tail;
    // cur를 리스트의 마지막 노드의 다음 노드로 설정
    plist->cur = plist->tail->next;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};
// - 두 번째 이후의 노드
int LNext(List* plist, Data* pdata)
{
    // 저장된 노드가 없을 경우 실패
    if (plist->tail == NULL) return FALSE;
    // before를 현재 cur이 가리키는 노드로 설정
    plist->before = plist->cur;
    // cur을 현재 cur이 가리키는 노드의 다음 노드로 설정
    plist->cur = plist->cur->next;
    // cur이 가리키는 노드의 데이터를 pdata가 가리키는 메모리에 저장
    *pdata = plist->cur->data;
    // 성공
    return TRUE;
};

// 삭제
Data LRemove(List* plist)
{
    // cur이 가리키는 노드를 삭제할 노드로 지정
    Node* rpos = plist->cur;
    Data rdata = rpos->data;

    // 삭제할 노드가 tail이 가리키는 노드일 경우
    if (rpos == plist->tail)
    {
        // 삭제할 노드가 리스트의 유일한 노드일 경우
        if (plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    // 삭제할 노드의 이전 노드와 삭제할 노드의 다음 노드를 서로 연결
    plist->before->next = plist->cur->next;
    // cur이 가리키는 노드를 삭제할 노드의 이전 노드로 설정
    plist->cur = plist->before;
    // 삭제할 노드의 메모리 할당 해제
    free(rpos);
    // 연결 리스트의 노드 수 감소
    (plist->numOfData)--;
    // 삭제한 노드의 데이터 반환
    return rdata;
};

// 노드의 수 반환
int LCount(List* plist)
{
    return plist->numOfData;
};