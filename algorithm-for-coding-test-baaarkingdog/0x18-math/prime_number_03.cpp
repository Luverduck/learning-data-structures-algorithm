#include <bits/stdc++.h>

using namespace std;

// n 이하의 모든 소수 판별 (에라토스테네스의 체)
void factorization(int n)
{
    // 2부터 √n 사이의 자연수 i에 대하여
    for (int i = 2; i * i <= n; ++i)
    {
        // n이 i로 나누어 떨어질 경우 나누어 떨어지지 않을 때까지 n을 i로 나눗셈
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
        // n이 i로 나누어 떨이지지 않을 경우 i의 값 증가
    }
    // 나눗셈 연산 후 n의 최종값이 1이 아닐 경우 해당 값도 인수로 포함
    if (n != 1) cout << n;
}

void solution()
{
    factorization(102);
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}