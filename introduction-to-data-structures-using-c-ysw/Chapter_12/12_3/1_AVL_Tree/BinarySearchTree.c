#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "AVLRebalance.h"
#include <stdio.h>
#include <stdlib.h>

// 이진 탐색 트리에 저장할 데이터의 자료형
typedef BTData BSTData;

// 이진 탐색 트리 생성 및 초기화
// - pRoot : BTreeNode의 루트 노드 자리를 가리키는 포인터
void BSTMakeAndInit(BTreeNode** pRoot)
{
    *pRoot = NULL;
};

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
    return GetData(bst);
};

// 이진 탐색 트리에 데이터 저장 및 리밸런싱
BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
    // 데이터 저장
    // i) 루트 노드가 NULL일 경우
    if (*pRoot == NULL)
    {
        // 루트 노드 생성
        *pRoot = MakeBTreeNode();
        // 루트 노드에 데이터 저장
        SetData(*pRoot, data);
    }
    // ii) 저장할 데이터가 현재 노드의 데이터보다 작을 경우
    else if (data < GetData(*pRoot))
    {
        // 왼쪽 서브 트리를 탐색하여 노드 추가 및 데이터 저장
        BSTInsert(&((*pRoot)->left), data);
        // 재귀 호출이 끝나기 전에 현재 pRoot 노드의 리밸런싱 실행
        *pRoot = Rebalance(pRoot);
    }
    // iii) 저장할 데이터가 현재 노드의 데이터보다 클 경우
    else if (data > GetData(*pRoot))
    {
        // 오른쪽 서브 트리를 탐색하여 노드 추가 및 데이터 저장
        BSTInsert(&((*pRoot)->right), data);
        // 재귀 호출이 끝나기 전에 현재 pRoot 노드의 리밸런싱 실행
        *pRoot = Rebalance(pRoot);
    }
    // iv) 그 외 (저장할 데이터가 현재 노드의 데이터와 같을 경우)
    else 
    {
        // NULL 반환 (이진 탐색 트리에 중복값 저장 방지)
        return NULL;
    }
    // 데이터 저장 후 루트 노드 반환
    // - 리밸런싱에 의해 루트 노드가 변경될 수 있음
    return *pRoot;
};

// 이진 탐색 트리에서 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* pnode, BSTData target)
{
    // 변수 할당
    BTreeNode* cNode = pnode; // 현재 노드
    BSTData cdata;          // 현재 노드의 데이터

    // 말단 노드의 하위 노드에 도달할 때까지 반복
    while (cNode != NULL) // 현재 위치의 노드가 NULL이 될 때까지 반복
    {
        // 현재 노드의 데이터
        cdata = GetData(cNode);

        // 이진 탐색 트리의 데이터 탐색
        if (target == cdata) // 탐색에 성공할 경우
            return cNode;    // 해당 노드의 데이터 반환
        else if (target < cdata) // 찾을 데이터가 현재 노드의 데이터보다 작은 경우
            return GetLeftSubtree(cNode);   // 왼쪽 서브 트리 탐색
        else // 찾을 데이터가 현재 노드의 데이터보다 작은 경우
            return GetRightSubtree(cNode);  // 오른쪽 서브 트리 탐색
    }

    // 데이터를 발견하지 못한 경우
    return NULL;
};

// 이진 탐색 트리에서 데이터 삭제
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
    // 변수 선언
    BTreeNode* pVRoot = MakeBTreeNode();    // 가상의 부모 노드
    BTreeNode* pNode = pVRoot;              // 부모 노드
    BTreeNode* cNode = *pRoot;              // 현재 노드
    BTreeNode* dNode;                       // 삭제할 노드
    // 가상의 루트 노드 생성 및 루트 노드를 오른쪽 자식 노드로 설정한다.
    ChangeRightSubtree(pVRoot, *pRoot);
    // 삭제할 노드를 찾는다.
    while (cNode != NULL && GetData(cNode) != target)
    {
        // 현재 노드를 부모 노드로 설정
        pNode = cNode;
        // 이진 탐색
        if (target < GetData(cNode))        // 현재 노드의 값이 탐색 대상의 값보다 큰 경우
            cNode = GetLeftSubtree(cNode);  // 현재 노드를 왼쪽 서브 트리로 변경 
        else                                // 그 외의 경우
            cNode = GetRightSubtree(cNode); // 현재 노드를 오른쪽 서브 트리로 변경
    }
    // 삭제할 대상이 존재하지 않는 경우
    if (cNode == NULL)  // 말단 노드까지 도달한 경우
        return NULL;
    // 찾은 노드를 삭제할 노드로 설정
    dNode = cNode;
    // i) 삭제할 노드가 단말 노드인 경우
    if (GetLeftSubtree(dNode) == NULL && GetRightSubtree(dNode) == NULL)
    {
        // 삭제할 노드가 부모 노드의 왼쪽 자식 노드일 경우
        if (GetLeftSubtree(pNode) == dNode)
            RemoveLeftSubtree(pNode);
        // 삭제할 노드가 부모 노드의 오른쪽 자식 노드일 경우
        else
            RemoveRightSubtree(pNode);
    }
    // ii) 삭제할 노드가 하나의 자식 노드를 갖는 경우
    else if (GetLeftSubtree(dNode) == NULL || GetRightSubtree(dNode) == NULL)
    {
        // 변수 선언
        BTreeNode* dcNode; // 삭제할 노드의 자식 노드
        // 삭제할 노드의 자식 노드 설정
        if (GetLeftSubtree(dNode) != NULL)
            dcNode = GetLeftSubtree(dNode);
        else
            dcNode = GetRightSubtree(dNode);
        // 부모 노드의 왼쪽 자식 노드가 삭제할 노드일 경우
        if (GetLeftSubtree(pNode) == dNode)
            // 부모 노드의 왼쪽 자식 노드로 삭제할 노드의 자식 노드를 설정
            ChangeLeftSubtree(pNode, dcNode);
        // 부모 노드의 오른쪽 자식 노드가 삭제할 노드일 경우
        else
            // 부모 노드의 오른쪽 자식 노드로 삭제할 노드의 자식 노드를 설정
            ChangeRightSubtree(pNode, dcNode);
    }
    // iii) 삭제할 노드가 두 개의 자식 노드를 갖는 경우
    else
    {
        // 변수 선언
        BTreeNode* mNode = GetRightSubtree(dNode);  // 대체할 노드
        BTreeNode* mpNode = dNode;                  // 대체할 노드의 부모 노드
        int dData;                                  // 삭제할 노드에 저장된 데이터
        // 삭제할 노드를 대체할 노드 탐색 
        // - 오른쪽 서브 트리에서 가장 작은 값을 탐색하는 방법 사용
        while (GetLeftSubtree(mNode) != NULL) // 말단 노드에 도달할 때까지 반복
        {
            // 현재 노드의 부모 노드를 현재 노드로 설정
            mpNode = mNode;
            // 현재 노드를 현재 노드의 자식 노드로 변경
            mNode = GetLeftSubtree(mNode);
        }
        // 삭제할 노드에 삭제 후 대체할 노드를 대입
        dData = GetData(mNode);
        // 삭제할 노드에 대체할 노드의 값 대입
        SetData(dNode, dData);
        // 대체할 노드의 부모 노드와 자식 노드를 연결한다.
        if (GetLeftSubtree(mpNode) == mNode)    // 대체할 노드가 왼쪽 자식 노드일 경우
            // 부모 노드의 왼쪽 자식 노드로 대체할 노드의 오른쪽 자식 노드 연결
            ChangeLeftSubtree(mpNode, GetRightSubtree(mNode));
        else                                    // 대체할 노드가 오른쪽 자식 노드일 경우
            // 부모 노드의 오른쪽 자식 노드로 대체할 노드의 오른쪽 자식 노드 연결
            ChangeRightSubtree(mpNode, GetRightSubtree(mNode));
    }
    // 삭제할 노드가 루트 노드인 경우 
    // - 가상 루트 노드의 오른쪽 자식 노드가 루트 노드가 아닌 경우
    if (GetRightSubtree(pVRoot) != *pRoot)
    {
        // 현재 가상 루트 노드의 오른쪽 자식 노드를 루트 노드로 변경
        *pRoot = GetRightSubtree(pVRoot);
    }
    // 가상 루트 노드의 메모리 해제
    free(pVRoot);
    // 노드 제거 후 리밸런싱 실행
    *pRoot = Rebalance(pRoot);
    // 삭제한 노드 반환
    return dNode;
};

// 이진 트리의 노드를 순회할 때 실행할 함수
void ShowIntData(int data)
{
    // 노드의 데이터 출력
    printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode* pnode)
{
    // 이진 트리를 중위 순회하며 노드의 데이터 출력
    InorderTraverse(pnode, ShowIntData);
};