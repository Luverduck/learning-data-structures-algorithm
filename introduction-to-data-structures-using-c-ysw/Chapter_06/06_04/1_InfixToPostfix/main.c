// Chpater 06. 스택 (Stack)
// 06-4. 계산기 프로그램 구현

#include <stdio.h>
#include "InfixToPostfix.h"

int main()
{
    // 변환할 중위 표현식
    char exp1[] = "1+2*3";              // 예상 결과 : 123*+
    char exp2[] = "(1+2)*3";            // 예상 결과 : 12+3*
    char exp3[] = "((1-2)+3)*(5-2)";    // 예상 결과 : 12-3+52-*
    char exp4[] = "((1+(2*3))/4)";      // 예상 결과 : 123*+4/

    // 중위 표현식을 후위 표현식으로 변환
    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);
    ConvToRPNExp(exp4);

    // 변환 결과 출력
    printf("%s\n", exp1);
    printf("%s\n", exp2);
    printf("%s\n", exp3);
    printf("%s\n", exp4);

    return 0;
}