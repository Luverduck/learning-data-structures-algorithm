// Chapter 08. 트리 (Tree)
// 08-2. 이진 트리의 구현

#include <stdio.h>
#include "BinaryTree.h"

// 부모 노드 방문시 해당 노드의 데이터 출력
void ShowInData(int data)
{
    printf("%d ", data);
};

int main()
{
    // 노드 생성
    BTreeNode* node1 = MakeBTreeNode();
    BTreeNode* node2 = MakeBTreeNode();
    BTreeNode* node3 = MakeBTreeNode();
    BTreeNode* node4 = MakeBTreeNode();
    BTreeNode* node5 = MakeBTreeNode();
    BTreeNode* node6 = MakeBTreeNode();

    // 노드의 데이터 초기화
    SetData(node1, 1);
    SetData(node2, 2);
    SetData(node3, 3);
    SetData(node4, 4);
    SetData(node5, 5);
    SetData(node6, 6);

    // 이진 트리 생성
    MakeLeftSubtree(node1, node2);
    MakeRightSubtree(node1, node3);
    MakeLeftSubtree(node2, node4);
    MakeRightSubtree(node2, node5);
    MakeRightSubtree(node3, node6);

    // 중위 순회
    printf("Inorder Traverse\n");
    InorderTraverse(node1, ShowInData);
    printf("\n");
    // 전위 순회
    printf("Preorder Traverse\n");
    PreorderTraverse(node1, ShowInData);
    printf("\n");
    // 후위 순회
    printf("Postorder Traverse\n");
    PostorderTraverse(node1, ShowInData);

    return 0;
}