// Chapter 08. 트리 (Tree)
// 08-4. 수식 트리(Expression Tree)의 구현

#include <stdio.h>
#include "ExpressionTree.h"

int main()
{
    char exp[] = "12+7*";

    BTreeNode* expTree = MakeExpTree(exp);

    printf("중위 표기법의 수식 : ");
    ShowInfixTypeExp(expTree);      // 결과 : 1 + 2 * 7
    printf("\n");

    printf("전위 표기법의 수식 : ");
    ShowPrefixTypeExp(expTree);     // 결과 : * + 1 2 7
    printf("\n");

    printf("후위 표기법의 수식 : ");
    ShowPostfixTypeExp(expTree);    // 결과 : 1 2 + 7 *
    printf("\n");

    printf("연산의 결과 : %d\n", EvaluateExpTree(expTree));

    return 0;
};