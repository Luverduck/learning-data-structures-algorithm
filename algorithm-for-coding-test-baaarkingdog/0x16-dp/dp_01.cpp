#include <bits/stdc++.h>

using namespace std;

// 피보나치 수열의 n번째 항 반환 (재귀)
int fibo_recursion(int n)
{
    if (n <= 1) return 1;
    return fibo_recursion(n - 1) + fibo_recursion(n - 2);
}

// 피보나치 수열의 n번째 항 반환 (다이나믹 프로그래밍)
int fibo_dp(int n)
{
    int f[20];
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

void solution()
{

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