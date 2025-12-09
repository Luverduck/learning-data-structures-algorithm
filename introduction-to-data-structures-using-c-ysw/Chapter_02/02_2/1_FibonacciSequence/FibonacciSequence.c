// Chapter 02. 재귀 (Recursion)
// 02-2. 재귀의 활용
/*
    피보나치 수열 (Fibonacci Sequence)
    f(n+2) = f(n+1) + f(n)
    1, 1, 2, 3, 5, 8, 13, ...
*/

int fibonacci(int n)
{
    // 제 1항과 제 2항의 값은 1로 정한다.
    if(n == 1) 
        return 0;
    else if(n == 2) 
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

#include <stdio.h>
int main()
{
    int num = 10;
    int result;

    // 피보나치 함수 호출
    result = fibonacci(num);

    // 결과
    printf("Fibonacci of %d : %d", num, result);
}