#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 연산자 우선순위값 반환 (Get Operator Precedence)
int GetOpPrec(char op)
{
    switch (op)
    {
        case '*' :
        case '/' :
            return 5;
        case '+' :
        case '-' : 
            return 3;
        case '(' :
            return 1;
    }

    return -1;
}

// 두 연산자의 우선순위 비교
int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else 
        return 0;
}

// 중위 표현식을 후위 표현식으로 변환 (Convert to Reverse Polish Expression)
void ConvToRPNExp(char exp[])
{
    // 수식의 문자열 길이
    int expLen = strlen(exp);
    // 변환된 수식을 저장할 메모리 (출력 큐)
    char* convExp = (char*)malloc(sizeof(char) * expLen + 1);
    // 변환된 수식을 저장할 메모리의 index
    int idx = 0;
    // 문자열의 특정 index 요소의 값
    char token;

    // 연산자 스택 생성 및 초기화
    Stack stack;
    StackInit(&stack);
    // 연산자 스택에서 꺼낸 연산자 문자를 저장할 메모리
    char popOp;
    // convExp가 가리키는 메모리의 값을 모두 0으로 초기화
    memset(convExp, 0, sizeof(char) * expLen + 1);

    // 수식 변환
    for(int i = 0; i < expLen; ++i)
    {   
        // 수식의 i번째 요소
        token = exp[i];
        if (isdigit(token))                     // 숫자일 경우
            convExp[idx++] = token;             // 출력 큐에 저장 후 index 증가
        else                                    // 숫자가 아닐 경우 (연산자)
        {
            switch (token)                      // 연산자 종류에 따른 분기 처리
            {
                case '(' :                      // '(' 일 경우
                    SPush(&stack, token);       // 연산자 스택에 넣기
                    break;
                case ')' :                      // ')'일 경우
                    while (1)
                    {
                        popOp = SPop(&stack);   // 연산자 스택에서 꺼내기
                        if (popOp == '(')       // '('가 나올 때까지
                            break;
                        convExp[idx++] = popOp; // 꺼낸 연산자를 출력 큐에 저장
                    }
                    break;
                case '+' :                      // 그 외 연산자의 경우
                case '-' :
                case '*' :
                case '/' :
                    // 연산자 스택에 저장된 연산자외 우선순위을 비교 
                    while (!SIsEmpty(&stack) && WhoPrecOp(SPeak(&stack), token) >= 0) // token의 연산자보다 우선순위가 낮은 연산자가 나올 때까지 
                        convExp[idx++] = SPop(&stack); // 연산자 스택에 저장된 연산자를 꺼내서 출력 큐에 저장
                    SPush(&stack, token); // token의 연산자를 연산자 스택에 저장
                    break;
            }
        }
    }
    // 연산자 스택에 저장된 모든 연산자를 출력 큐에 저장
    while (!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    // 출력 큐에 저장된 문자열을 exp에 복사
    strcpy(exp, convExp);

    // 출력 큐의 메모리 해제
    free(convExp);
}