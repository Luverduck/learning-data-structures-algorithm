#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11047
 */

int N, K;
int A[1000001];

void greedy()
{
    int res = 0;
    for (int i = N; i >= 1; --i)
    {
        if (A[i] > K) continue;
        res += K / A[i];
        K %= A[i];
    }
    cout << res;
}

void solution()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    greedy();
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