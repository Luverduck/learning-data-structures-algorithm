#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11659
 */

int N, M, num, i, j;
int d[100002];

void dp()
{
    d[0] = 0;
    for (int n = 1; n <= N; ++n)
    {
        cin >> num;
        d[n] = d[n - 1] + num;
    }
}

void solution()
{
    cin >> N >> M;
    dp();
    while (M--)
    {
        cin >> i >> j;
        cout << d[j] - d[i - 1] << "\n";
    }
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