#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1937
 */

int N;
int D[505][505];
int board[505][505];
int dx[4] { 1, 0, -1, 0 };
int dy[4] { 0, 1, 0, -1 };

bool is_out_of_bounds(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= N;
}

int go(int x, int y)
{
    if (D[x][y] != -1) return D[x][y];
    D[x][y] = 1;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (is_out_of_bounds(nx, ny) || board[nx][ny] <= board[x][y]) continue;
        D[x][y] = max(D[x][y], go(nx, ny) + 1);
    }
    return D[x][y];
}

void solution()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            D[i][j] = -1;
        }
    }
    int mx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            mx = max(mx, go(i, j));
        }
    }
    cout << mx;
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