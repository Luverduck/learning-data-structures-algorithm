#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11047
 */

void greedy()
{
    int N = 3, K = 18;
    int A[4] { 0, 1, 9, 10 };

    int res = 0;
    for (int i = N; i >= 1; --i)
    {
        if (A[i] > K) continue;
        res += K / A[i];
        K %= A[i];
    }
    cout << res << "\n";
}

void dp()
{
    int N = 3, K = 18;
    int A[4] { 0, 1, 9, 10 };
    int d[19];

    d[0] = 0;
    for (int i = 1; i <= K; ++i)
    {
        d[i] = d[i - 1] + 1;
        if (i >= A[2]) d[i] = min(d[i], d[i - A[2]] + 1);
        if (i >= A[3]) d[i] = min(d[i], d[i - A[3]] + 1);
    }
    cout << d[18];
}

void solution()
{
    greedy();
    dp();
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