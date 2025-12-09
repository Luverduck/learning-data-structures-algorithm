#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

// 초기화
void ListInit(List* plist)
{
    plist->head = (Node*)malloc(sizeof(Node));  // 더미 노드 생성 및 리스트의 head로 설정
    plist->head->next = NULL;                   // 더미 노드의 다음 노드 주소를 NULL로 초기화
    plist->numOfData = 0;                       // 리스트의 노드 갯수를 0으로 초기화 (더미 노드는 노드로 취급하지 않는다.)
    plist->comp = NULL;                         // [추가] 정렬 기준 초기화
};

// [추가] 정렬 기준 설정 (인자로 전달된 함수를 이용한 정렬 기준 함수로 설정)
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
};

// 비정렬 삽입
void FInsert(List* plist, LData data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 생성한 노드를 head에 추가
    // 1) 생성한 노드의 다음 노드를 기존 head의 다음 노드로 설정
    newNode->next = plist->head->next;
    // 2) 생성한 노드를 head 노드로 설정
    plist->head->next = newNode;
    // 리스트에 저장된 데이터의 수 증가
    (plist->numOfData)++;
};

// [추가] 정렬 삽입
void SInsert(List* plist, LData data)
{
    // 노드 생성 및 초기화
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // pred를 더미 노드로 초기화
    Node* pred = plist->head;

    // [추가] 1) 생성된 노드가 삽입될 위치
    // - 마지막 노드가 아니면서 
    // - 삽입할 노드의 데이터가 현재 노드의 데이터보다 큰 경우(순서가 뒤인 경우)
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        // 다음 노드로 이동
        pred = pred->next;
    }

    // 생성한 노드 연결
    // - 2) 오른쪽 연결
    newNode->next = pred->next;
    // - 3) 왼쪽 연결
    pred->next = newNode;

    // 리스트에 저장된 데이터의 수 증가
    (plist->numOfData)++;
};

// [추가] 삽입
void LInsert(List* plist, LData data)
{
    // 정렬 기준이 설정되어 있는지 여부에 따라 비정렬 / 정렬 삽입
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
};

// 조회
// - 리스트의 첫 번째 데이터
int LFirst(List* plist, LData* pdata)
{
    // head가 가리키는 노드의 다음 노드 주소가 NULL일 경우
    if (plist->head->next == NULL)
        return FALSE;
    // before이 가리키는 노드를 더미 노드로 지정
    plist->before = plist->head;
    // cur이 가리키는 노드를 첫 번째 노드로 지정 (더미 노드의 다음 노드)
    plist->cur = plist->head->next;
    // 첫 번째 노드의 데이터 반환
    *pdata = plist->cur->data;

    return TRUE;
};
// - 리스트의 첫 번째 이후 데이터
int LNext(List* plist, LData* pdata)
{
    // cur이 가리키는 노드의 다음 노드 주소가 NULL일 경우
    if (plist->cur->next == NULL)
        return FALSE;
    // before이 가리키는 노드를 cur이 가리키는 노드로 지정
    plist->before = plist->cur;
    // cur이 가리키는 노드를 cur이 가리키던 노드의 다음 노드로 지정
    plist->cur = plist->cur->next;
    // cur이 가리키는 노드의 데이터 반환
    *pdata = plist->cur->data;

    return TRUE;
};

// 삭제
LData LRemove(List* plist)
{
    // 삭제할 노드와 그 데이터 선택
    Node* rpos = plist->cur;
    LData rdata = rpos->data;

    // 노드 연결 해제
    // 1) before가 가리키는 노드의 다음 노드를 cur가 가리키는 노드의 다음 노드로 지정
    plist->before->next = plist->cur->next;
    // 2) cur가 가리키는 노드를 before가 가리키는 노드로 지정
    plist->cur = plist->before;

    // 노드 삭제
    free(rpos);             // 메모리 할당 해제
    (plist->numOfData)--;   // 전체 노드의 갯수 감산

    return rdata;
};

// 리스트에 저장된 데이터의 갯수 반환
int LCount(List* plist)
{
    return plist->numOfData;
};