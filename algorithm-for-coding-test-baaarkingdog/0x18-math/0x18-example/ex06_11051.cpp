#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11051
 */

int N, K;
int comb[1001][1001];
int mod = 10007;

int dp()
{
    for (int i = 1; i <= N; ++i)
    {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; ++j)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    }
    return 0;
}

void solution()
{
    cin >> N >> K;
    dp();
    cout << comb[N][K];
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