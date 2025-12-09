// Chapter 02. 재귀 (Recursion)
// 02-1. 함수의 재귀적 호출의 이해
/*
    팩토리얼
    5!  = 5 * 4!
        = 5 * 4 * 3!
        = 5 * 4 * 3 * 2!
        = 5 * 4 * 3 * 2 * 1!
*/

// 팩토리얼 함수
int factorial(int n)
{
    // n이 0일 경우 0! = 1
    if(n == 0)
        return 1;
    // 그 외 n! = n * (n-1)!
    return n * factorial(n - 1);
}

#include <stdio.h>
int main()
{
    int num = 5;
    int result;

    // 팩토리얼
    // 5! = 5 * 4 * 3 * 2 * 1
    result = factorial(num);

    // 결과
    printf("Factorial of %d : %d\n", num, result);

    return 0;
};