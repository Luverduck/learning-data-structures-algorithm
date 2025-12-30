#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1149
 */

int N;
int r[1001], g[1001], b[1001];
int d[1001][3];

void dp()
{
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];
    for (int i = 2; i <= N; ++i)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }
}

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> r[i] >> g[i] >> b[i];
    dp();
    cout << min(d[N][0], min(d[N][1], d[N][2]));
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