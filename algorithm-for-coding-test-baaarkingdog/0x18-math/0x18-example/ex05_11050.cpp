#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11050
 */

int binomial(int n, int k)
{
    int res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    for (int i = 2; i <= k; ++i) res /= i;
    for (int i = 2; i <= (n - k); ++i) res /= i;
    return res;
}

void solution()
{
    int N, K;
    cin >> N >> K;
    cout << binomial(N, K);
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