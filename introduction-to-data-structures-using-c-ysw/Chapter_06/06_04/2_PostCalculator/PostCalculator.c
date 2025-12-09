#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    // 수식 문자열의 길이
    int expLen = strlen(exp);
    // 수식 문자열의 i번째 문자 
    char token;
    // 스택에서 꺼낸 피연산자
    char op1, op2;

    // 스택 초기화
    Stack stack;
    StackInit(&stack);

    for (int i = 0; i < expLen; ++i)
    {
        token = exp[i];

        if (isdigit(token))
        {
            // 문자 형태의 정수를 숫자로 변환
            SPush(&stack, token - '0');
        }
        else
        {
            // 스택에서 피연산자 2개 꺼내기
            op2 = SPop(&stack);
            op1 = SPop(&stack);
            // 연산자 종류에 따라 다른 연산 실행
            switch (token)
            {
                case '+' :
                    SPush(&stack, op1 + op2);
                    break;
                case '-' :
                    SPush(&stack, op1 - op2);
                    break;
                case '*' :
                    SPush(&stack, op1 * op2);
                    break;
                case '/' :
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }
    
    return SPop(&stack);
};
