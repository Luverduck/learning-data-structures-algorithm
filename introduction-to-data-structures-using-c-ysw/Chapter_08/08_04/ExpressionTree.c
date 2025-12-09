#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ExpressionTree.h"
#include "BinaryTree.h"
#include "ListBaseStack.h"

// 수식 트리 구성
BTreeNode* MakeExpTree(char exp[])
{
    // 수식 문자열의 문자를 저장할 노드
    BTreeNode* pnode;
    // 수식 문자열의 길이
    int expLen = strlen(exp);
    // 피연산자를 저장할 스택 생성 및 초기화
    Stack stack;
    StackInit(&stack);
    // 수식 문자열의 길이만큼 반복
    for (int i = 0; i < expLen; ++i)
    {
        // 노드 생성 및 초기화
        pnode = MakeBTreeNode();
        // 만난 문자에 따라 서로 다른 처리
        if (isdigit(exp[i]))// 문자열의 i번째 문자가 피 연산자일 경우
        {
            // 노드에 피 연산자의 값 저장 (문자를 정수로 바꿔서 저장)
            SetData(pnode, exp[i] - '0');
        }
        else // 문자열의 i번째 문자가 연산자일 경우
        {
            // 노드에 연산자의 값 저장
            SetData(pnode, exp[i]);
            // 스택에서 피 연산자 2개를 꺼내서 트리 생성
            MakeRightSubtree(pnode, SPop(&stack));
            MakeLeftSubtree(pnode, SPop(&stack));
        }
        // 노드를 스택에 저장
        // - 문자열의 i번째 문자가 피 연산자일 경우 노드 저장
        // - 문자열의 i번째 문자가 연산자일 경우 트리의 부모 노드 저장
        SPush(&stack, pnode);
    }
    // 최종적으로 스택에 저장된 수식의 연산 결과값 반환
    return SPop(&stack);
};

// 서브 트리의 부모 노드 방문시 실행할 함수
void ShowNodeData(int data)
{
    // data의 범위에 따라 다른 처리
    if (data >= 0 && data <= 9) // data가 0 ~ 9 사이일 경우 (피 연산자) 
        printf("%d ", data);    // 정수 출력
    else                        // 그렇지 않을 경우 (연산자)
        printf("%c ", data);    // 문자 출력
}

// 중위 표기법으로 출력
void ShowInfixTypeExp(BTreeNode* pnode)
{
    InorderTraverse(pnode, ShowNodeData);
};

// 전위 표기법으로 출력
void ShowPrefixTypeExp(BTreeNode* pnode)
{
    PreorderTraverse(pnode, ShowNodeData);
};

// 후위 표기법으로 출력
void ShowPostfixTypeExp(BTreeNode* pnode)
{
    PostorderTraverse(pnode, ShowNodeData);
};

// 수식 트리 계산
int EvaluateExpTree(BTreeNode* pnode)
{
    // 현재 서브 트리의 왼쪽과 오른쪽에 연결된 서브 트리 연산 결과
    int opLeft, opRight;
    // 왼쪽 자식 노드와 오른쪽 자식 노드가 NULL일 경우
    if (GetLeftSubtree(pnode) == NULL && GetRightSubtree(pnode) == NULL)
        return GetData(pnode); // 부모 노드의 데이터 반환
    // 왼쪽 서브 트리 연산 후 결과 반환
    opLeft = EvaluateExpTree(GetLeftSubtree(pnode));
    // 오른쪽 서브 트리 연산 후 결과 반환
    opRight = EvaluateExpTree(GetRightSubtree(pnode));
    // 현재 서브 트리의 부모 노드의 값(연산자)에 따라 다른 처리
    switch (GetData(pnode))
    {
        case '+' :
            return opLeft + opRight;
        case '-' :
            return opLeft - opRight;
        case '*' :
            return opLeft * opRight;
        case '/' :
            return opLeft / opRight;
    }

    return 0;
};