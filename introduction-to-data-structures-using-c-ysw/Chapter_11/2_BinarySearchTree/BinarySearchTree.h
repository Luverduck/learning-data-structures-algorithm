#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

// 이진 탐색 트리에 저장할 데이터의 자료형
typedef BTData BSTData;

// 이진 탐색 트리 생성 및 초기화
void BSTMakeAndInit(BTreeNode** proot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst);

// 이진 탐색 트리에 데이터 저장
void BSTInsert(BTreeNode** proot, BSTData data);

// 이진 탐색 트리에서 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* pnode, BSTData target);

// 이진 탐색 트리에서 데이터 삭제
BTreeNode* BSTRemove(BTreeNode** proot, BSTData target);

// 이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode* pnode);

#endif