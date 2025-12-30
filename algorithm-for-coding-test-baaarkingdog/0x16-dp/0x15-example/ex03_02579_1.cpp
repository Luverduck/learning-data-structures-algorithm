#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2579
 */

int N;
int s[301];
int d[301][3];

void dp()
{
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];
    for (int i = 3; i <= N; ++i)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
        d[i][2] = d[i - 1][1] + s[i];
    }
}

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> s[i];
    dp();
    cout << max(d[N][1], d[N][2]);
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