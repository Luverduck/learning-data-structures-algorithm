#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1915
 */

int N, M;
string board[1005];
int D[1005][1005];

void solution()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    for (int i = 0; i < N; ++i)
        D[i][0] = board[i][0] - '0';
    for (int j = 0; j < M; ++j)
        D[0][j] = board[0][j] - '0';

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < M; ++j)
        {
            if (board[i][j] == '0') continue;
            D[i][j] = min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]}) + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            res = max(res, D[i][j]);
        }
    }
    cout << res *  res;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}