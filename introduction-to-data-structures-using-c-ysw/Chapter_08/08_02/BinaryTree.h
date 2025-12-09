#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

// 노드에 저장할 데이터의 자료형
typedef int BTData;

// 연결 리스트 기반 트리의 노드 정의
typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
} BTreeNode;

// 트리 노드 생성 및 초기화
BTreeNode* MakeBTreeNode(void);

// 트리 노드의 데이터 조회
BTData GetData(BTreeNode* pnode);

// 트리 노드에 데이터 저장
void SetData(BTreeNode* pnode, BTData data);

// 서브 트리 조회
BTreeNode* GetLeftSubtree(BTreeNode* pnode);
BTreeNode* GetRightSubtree(BTreeNode* pnode);

// 서브 트리 생성
void MakeLeftSubtree(BTreeNode* ppnode, BTreeNode* pcnode);
void MakeRightSubtree(BTreeNode* ppnode, BTreeNode* pcnode);

#endif