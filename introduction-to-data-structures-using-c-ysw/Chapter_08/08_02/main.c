// Chapter 08. 트리 (Tree)
// 08-2. 이진 트리의 구현

#include <stdio.h>
#include "BinaryTree.h"

int main()
{
    BTreeNode* node1 = MakeBTreeNode();
    BTreeNode* node2 = MakeBTreeNode();
    BTreeNode* node3 = MakeBTreeNode();
    BTreeNode* node4 = MakeBTreeNode();

    SetData(node1, 1);
    SetData(node2, 2);
    SetData(node3, 3);
    SetData(node4, 4);

    MakeLeftSubtree(node1, node2);
    MakeRightSubtree(node1, node3);
    MakeLeftSubtree(node2, node4);

    printf("%d\n", GetData(GetLeftSubtree(node1)));
    printf("%d\n", GetData(GetLeftSubtree(GetLeftSubtree(node1))));

    return 0;
}