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