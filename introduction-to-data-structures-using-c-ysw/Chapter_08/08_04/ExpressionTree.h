#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

// BTreeNode 자료형을 사용하기 위함
#include "BinaryTree.h"

// 수식 트리 구성
BTreeNode* MakeExpTree(char exp[]);

// 중위 표기법으로 출력
void ShowInfixTypeExp(BTreeNode* pnode);

// 전위 표기법으로 출력
void ShowPrefixTypeExp(BTreeNode* pnode);

// 후위 표기법으로 출력
void ShowPostfixTypeExp(BTreeNode* pnode);

// 수식 트리 계산
int EvaluateExpTree(BTreeNode* pnode);

#endif