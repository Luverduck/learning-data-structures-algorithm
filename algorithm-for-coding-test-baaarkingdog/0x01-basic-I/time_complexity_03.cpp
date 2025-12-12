#include <bits/stdc++.h>

using namespace std;

/*
 *  문제 3.
 *  N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성하라.
 *  N은 10억 이하의 자연수이다.
 */
int func3(int N)
{
    for (int i = 1; i * i <= N; ++i)
    {
        if (i * i == N) return 1;
    }
    return 0;
}

int main()
{
    int N = 9;
    int res = func3(N);
    cout << res;
}