// Chapter 12. 탐색 (Search) 2
// 12-3. 이진 탐색 트리의 리밸런싱

#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
    BTreeNode* avlRoot;
    BTreeNode* clNode;
    BTreeNode* crNode;
    BSTMakeAndInit(&avlRoot);

    BSTInsert(&avlRoot, 1);
    BSTInsert(&avlRoot, 2);
    BSTInsert(&avlRoot, 3);
    BSTInsert(&avlRoot, 4);
    BSTInsert(&avlRoot, 5);
    BSTInsert(&avlRoot, 6);
    BSTInsert(&avlRoot, 7);
    BSTInsert(&avlRoot, 8);
    BSTInsert(&avlRoot, 9);
    
    printf("LV 0.\t%d\n", GetData(avlRoot));
    
    printf("LV 1.\t");
    BTreeNode* left_LV1 = GetLeftSubtree(avlRoot);
    BTreeNode* right_LV1 = GetRightSubtree(avlRoot);
    printf("%d\t\t%d\n", GetData(left_LV1), GetData(right_LV1));

    printf("LV 2.\t");
    BTreeNode* left_left_LV2 = GetLeftSubtree(left_LV1);
    BTreeNode* left_right_LV2 = GetRightSubtree(left_LV1);
    BTreeNode* right_left_LV2 = GetLeftSubtree(right_LV1);
    BTreeNode* right_right_LV2 = GetRightSubtree(right_LV1);
    printf("%d\t%d\t%d\t%d\n", GetData(left_left_LV2), GetData(left_right_LV2), GetData(right_left_LV2), GetData(right_right_LV2));

    return 0;
}