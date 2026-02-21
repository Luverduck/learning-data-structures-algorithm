#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/9084
 */

int T, N, M;
int C[22];
int D[22][10005];

void solution()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> C[i];
            D[i][0] = 1;
        }
        cin >> M;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                D[i][j] = 0;
                if (i - 1 >= 0)
                    D[i][j] += D[i - 1][j];
                if (j - C[i] >= 0)
                    D[i][j] += D[i][j - C[i]];
            }
        }
        cout << D[N - 1][M] << "\n";
    }
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