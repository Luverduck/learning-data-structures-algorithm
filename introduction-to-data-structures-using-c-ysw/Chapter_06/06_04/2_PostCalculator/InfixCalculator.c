#include <string.h>
#include <stdlib.h>

#include "InfixCalculator.h"

#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
    // 중위 표기법으로 작성된 수식 문자열의 길이
    int len = strlen(exp);
    // 반환할 연산 결과
    int ret;
    // 수식 문자열을 저장할 메모리 생성
    char* expcpy = (char*)malloc(len + 1);
    // 수식 문자열을 생성한 메모리에 복사
    strcpy(expcpy, exp);

    // 메모리에 저장된 수식 문자열을 후위 표기법으로 변환
    ConvToRPNExp(expcpy);
    // 후위 표기법으로 변환된 수식 연산 후 결과를 ret에 저장
    ret = EvalRPNExp(expcpy);

    // 수식 문자열을 저장했던 메모리 해제
    free(expcpy);
    // 연산 결과 반환
    return ret;
};