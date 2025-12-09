#include <stdlib.h>
#include "BinaryTree.h"

// 트리 노드 생성 및 초기화
BTreeNode* MakeBTreeNode(void)
{
    // 트리 노드 생성
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    // 트리 노드 초기화
    newNode->left = NULL;
    newNode->right = NULL;
    // 생성한 트리 노드의 주소 반환
    return newNode;
};

// 트리 노드의 데이터 조회
BTData GetData(BTreeNode* pnode)
{
    // 트리 노드의 데이터 반환
    return pnode->data;
};

// 트리 노드에 데이터 저장
void SetData(BTreeNode* pnode, BTData data)
{
    // 트리 노드에 데이터 저장
    pnode->data = data;
};

// 왼쪽 서브 트리 조회
BTreeNode* GetLeftSubtree(BTreeNode* pnode)
{
    // 트리 노드의 왼쪽 서브 트리 주소 반환
    return pnode->left;
};

// 오른쪽 서브 트리 조회
BTreeNode* GetRightSubtree(BTreeNode* pnode)
{
    // 트리 노드의 오른쪽 서브 트리 주소 반환
    return pnode->right;
};

// 왼쪽 서브 트리 생성
void MakeLeftSubtree(BTreeNode* ppnode, BTreeNode* pcnode)
{
    // 부모 노드의 왼쪽에 연결된 노드 주소가 존재하면
    if (ppnode->left != NULL)
        free(ppnode->left); // 해당 노드 메모리 해제
    // 부모 노드의 왼쪽에 자식 노드 추가
    ppnode->left = pcnode;
};

// 오른쪽 서브 트리 생성
void MakeRightSubtree(BTreeNode* ppnode, BTreeNode* pcnode)
{
    // 부모 노드의 오른쪽에 연결된 노드 주소가 존재하면
    if (ppnode->right != NULL)
        free(ppnode->right); // 해당 노드 메모리 해제
    // 부모 노드의 오른쪽에 자식 노드 추가
    ppnode->right = pcnode;
};

// 중위 순회
void InorderTraverse(BTreeNode* pnode, VisitFuncPtr action)
{
    // 방문한 노드가 NULL일 경우
    if (pnode == NULL) 
        return; // 서브 트리의 순회 중지
    // 왼쪽 자식 노드의 중위 순회
    InorderTraverse(pnode->left, action);
    // 부모 노드 방문시 인수로 전달받은 주소의 함수 실행
    action(pnode->data);
    // 오른쪽 자식 노드의 중위 순회
    InorderTraverse(pnode->right, action);
};

// 전위 순회
void PreorderTraverse(BTreeNode* pnode, VisitFuncPtr action)
{
    // 방문한 노드가 NULL일 경우
    if (pnode == NULL)
        return; // 서브 트리의 순회 중지
    // 부모 노드 방문시 인수로 전달받은 주소의 함수 실행
    action(pnode->data);
    // 왼쪽 자식 노드의 전위 순회
    PreorderTraverse(pnode->left, action);
    // 오른쪽 자식 노드의 전위 순회
    PreorderTraverse(pnode->right, action);
};

// 후위 순회
void PostorderTraverse(BTreeNode* pnode, VisitFuncPtr action)
{
    // 방문한 노드가 NULL일 경우
    if (pnode == NULL)
        return; // 서브 트리의 순회 중지
    // 왼쪽 자식 노드의 후위 순회
    PostorderTraverse(pnode->left, action);
    // 오른쪽 자식 노드의 후위 순회
    PostorderTraverse(pnode->right, action);
    // 부모 노드 방문시 인수로 전달받은 주소의 함수 실행
    action(pnode->data);
};

// [CH11-2] 이진 탐색 트리 구현을 위한 추가

// 왼쪽 자식 노드 삭제
BTreeNode* RemoveLeftSubtree(BTreeNode* pnode)
{
    BTreeNode* dnode;
    if (dnode != NULL)
    {
        dnode = pnode->left;
        pnode->left = NULL;
    }
    return dnode;
};

// 오른쪽 자식 노드 삭제
BTreeNode* RemoveRightSubtree(BTreeNode* pnode)
{
    BTreeNode* dnode;
    if (dnode != NULL)
    {
        dnode = pnode->right;
        pnode->right = NULL;
    }
    return dnode;
};

// 메모리 해제 없이 왼쪽 자식 노드 변경
void ChangeLeftSubtree(BTreeNode* main, BTreeNode* sub)
{
    // 메인 트리의 왼쪽 자식 노드 변경
    main->left = sub;
};

// 메모리 해제 없이 오른쪽 자식 노드 변경
void ChangeRightSubtree(BTreeNode* main, BTreeNode* sub)
{
    // 메인 트리의 오른쪽 자식 노드 변경
    main->right = sub;
};