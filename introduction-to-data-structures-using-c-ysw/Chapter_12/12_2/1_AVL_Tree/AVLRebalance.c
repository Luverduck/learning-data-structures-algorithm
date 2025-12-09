#include <stdio.h>
#include "BinaryTree.h"

// 트리의 높이
int GetHeight(BTreeNode* bst) 
{
    // 변수 선언
    int leftHeight;     // Left Height
    int rightHeight;     // Right Height
    // 말단 노드에 도달했을 때
    if (bst == NULL)
        return 0; // 높이 0 반환
    // 왼쪽 서브 트리와 오른쪽 서브 트리의 높이 반환
    leftHeight = GetHeight(GetLeftSubtree(bst));
    rightHeight = GetHeight(GetRightSubtree(bst));
    // 서브 트리의 높이 반환
    if (leftHeight > rightHeight)   // 왼쪽 서브 트리의 높이가 더 큰 경우
        return leftHeight + 1;      // 현재 노드를 고려하여 왼쪽 서브 트리 높이 + 1 반환
    else
        return rightHeight + 1;     // 현재 노드를 고려하여 오른쪽 서브 트리 높이 + 1 반환
};

// 왼쪽 서브 트리와 오른쪽 서브 트리의 높이차
int GetHeightDiff(BTreeNode* bst) 
{
    // 변수 선언
    int leftSubtreeHeight;    // Left Subtree Height
    int rightSubtreeHeight;    // Right Subtree Height
    // 말단 노드에 도달한 경우
    if (bst == NULL)
        return 0; // 높이차 0 반환
    // 왼쪽 서브 트리와 오른쪽 서브 트리의 높이 반환
    leftSubtreeHeight = GetHeight(GetLeftSubtree(bst));
    rightSubtreeHeight = GetHeight(GetRightSubtree(bst));
    // 두 서브 트리의 높이차 반환
    return leftSubtreeHeight - rightSubtreeHeight;
};

// LL 회전
BTreeNode* RotateLL(BTreeNode* bst) 
{
    // 변수 선언
    BTreeNode* pNode;   // 부모 노드
    BTreeNode* cNode;   // 자식 노드
    // 회전할 노드 설정
    pNode = bst;
    cNode = GetLeftSubtree(pNode);
    // LL 회전
    // 1) cNode의 오른쪽 서브 트리를 pNode의 왼쪽 서브 트리로 변경
    ChangeLeftSubtree(pNode, GetRightSubtree(cNode));
    // 2) pNode를 cNode의 오른쪽 서브 트리로 변경
    ChangeRightSubtree(cNode, pNode);
    // LL 회전을 통해 변경된 서브 트리의 루트 노드의 주소 반환
    return cNode;
};

// RR 회전
BTreeNode* RotateRR(BTreeNode* bst) 
{
    // 변수 선언
    BTreeNode* pNode;   // 부모 노드
    BTreeNode* cNode;   // 자식 노드
    // 회전할 노드 설정
    pNode = bst;
    cNode = GetRightSubtree(pNode);
    // RR 회전
    // 1) cNode의 왼쪽 서브 트리를 pNode의 오른쪽 서브 트리로 변경
    ChangeRightSubtree(pNode, GetLeftSubtree(cNode));
    // 2) pNode를 cNode의 왼쪽 서브 트리로 변경
    ChangeLeftSubtree(cNode, pNode);
    // RR 회전을 통해 변경된 서브 트리의 루트 노드의 주소 반환
    return cNode;
};

// LR 회전
BTreeNode* RotateLR(BTreeNode* bst) 
{
    // 변수 선언
    BTreeNode* pNode;   // 부모 노드
    BTreeNode* cNode;   // 자식 노드
    // 회전할 노드 설정
    pNode = bst;
    cNode = GetLeftSubtree(pNode);
    // 부분적 RR 회전
    // 1) cNode를 RR 회전
    // 2) RR 회전을 통해 변경된 서브 트리의 루트 노드를 pNode의 왼쪽 서브 트리로 변경
    ChangeLeftSubtree(pNode, RotateRR(cNode));
    // LL 회전
    // - pNode를 LL 회전
    return RotateLL(pNode);
};

// RL 회전
BTreeNode* RotateRL(BTreeNode* bst) 
{
    // 변수 선언
    BTreeNode* pNode;   // 부모 노드
    BTreeNode* cNode;   // 자식 노드
    // 회전할 노드 설정
    pNode = bst;
    cNode = GetRightSubtree(pNode);
    // 부분적 LL 회전
    // 1) cNode를 LL 회전
    // 2) LL 회전을 통해 변경된 서브 트리의 루트 노드를 pNode의 오른쪽 서브 트리로 변경
    ChangeRightSubtree(pNode, RotateLL(cNode));
    // RR 회전
    return RotateRR(pNode);
};

// 이진 탐색 트리의 리밸런싱
BTreeNode* Rebalance(BTreeNode** pRoot) 
{
    // 균형 인수 계산
    int heightDiff = GetHeightDiff(*pRoot);
    // 불균형 종류에 따른 리밸런싱 실행
    if (heightDiff >= 2) // 균형 인수가 +2 이상이면 LL 상태 또는 LR 상태
    {
        // 서브 트리의 왼쪽 자식 노드에 대하여
        // i) 왼쪽 자식 노드의 균형 인수가 0보다 크면 LL 상태
        if (GetHeight(GetLeftSubtree(*pRoot) > 0))
            *pRoot = RotateLL(*pRoot); // LL 회전
        // ii) 왼쪽 자식 노드의 균형 인수가 0보다 작거나 같으면 LR 상태
        else
            *pRoot = RotateLR(*pRoot); // LR 회전
    }
    // 불균형 종류에 따른 리밸런싱 실행
    if (heightDiff <= -2)
    {
        // 서브 트리의 오른쪽 자식 노드에 대하여
        // i) 오른쪽 자식 노드의 균형 인수가 0보다 작으면 RR 상태
        if (GetHeight(GetRightSubtree(*pRoot) < 0))
            *pRoot = RotateRR(*pRoot); // RR 회전
        // ii) 오른쪽 자식 노드의 균형 인수가 0보다 크거나 같으면 RL 상태
        else
            *pRoot = RotateRL(*pRoot); // RL 회전
    }
    // 리밸런싱을 통해 변경된 서브 트리의 루트 노드 주소 반환
    return *pRoot;
};