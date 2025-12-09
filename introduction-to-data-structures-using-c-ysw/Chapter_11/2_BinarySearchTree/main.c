// Chapter 11. 탐색 (Search)
// 11-2. 이진 탐색 트리

#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
    // 이진 트리의 데이터 삽입과 탐색
    /*// 변수 선언
    BTreeNode* bstRoot;
    BTreeNode* sNode;

    // 이진 탐색 트리 초기화
    BSTMakeAndInit(&bstRoot);

    // 이진 팀색 트리에 데이터 저장
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    // 이진 탐색 트리에서 데이터 탐색
    sNode = BSTSearch(bstRoot, 1);
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));*/

    // 변수 선언
    BTreeNode* bstRoot;
    BTreeNode* sNode;

    // 이진 탐색 트리 초기화
    BSTMakeAndInit(&bstRoot);

    // 이진 팀색 트리에 데이터 저장
    // 1, 2, 3, 4, 5, 6, 7, 8, 9
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);

    // 이진 탐색 트리에 저장된 모든 값 출력
    BSTShowAll(bstRoot);
    printf("\n");

    // 이진 탐색 트리에서 데이터 3 삭제 후 출력
    BSTRemove(&bstRoot, 3);
    BSTShowAll(bstRoot);
    printf("\n");

    // 이진 탐색 트리에서 데이터 8 삭제 후 출력
    BSTRemove(&bstRoot, 8);
    BSTShowAll(bstRoot);
    printf("\n");

    // 이진 탐색 트리에서 데이터 1 삭제 후 출력
    BSTRemove(&bstRoot, 1);
    BSTShowAll(bstRoot);
    printf("\n");

    // 이진 탐색 트리에서 데이터 6 삭제 후 출력
    BSTRemove(&bstRoot, 6);
    BSTShowAll(bstRoot);
    printf("\n");

    return 0;
}