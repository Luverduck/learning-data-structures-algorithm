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

// 서브 트리의 노드 방문시 실행할 함수의 포인터
typedef void (*VisitFuncPtr)(BTData data);

// 노드 순회
// - 중위 순회
void InorderTraverse(BTreeNode* pnode, VisitFuncPtr action);
// - 전위 순회
void PreorderTraverse(BTreeNode* pnode, VisitFuncPtr action);
// - 후위 순회
void PostorderTraverse(BTreeNode* pnode, VisitFuncPtr action);

// [CH11-2] 이진 탐색 트리 구현을 위한 추가

// 왼쪽 자식 노드 삭제
BTreeNode* RemoveLeftSubtree(BTreeNode* pnode);
// 오른쪽 자식 노드 삭제
BTreeNode* RemoveRightSubtree(BTreeNode* pnode);
// 메모리 해제 없이 왼쪽 자식 노드 변경
void ChangeLeftSubtree(BTreeNode* main, BTreeNode* sub);
// 메모리 해제 없이 오른쪽 자식 노드 변경
void ChangeRightSubtree(BTreeNode* main, BTreeNode* sub);

#endif