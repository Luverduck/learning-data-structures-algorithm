#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/12865
 */

int N, K;
int W[105];
int V[105];
int D[105][100005];

void solution()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> W[i] >> V[i];
        D[i][0] = 0;
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if (i - 1 >= 0)
                D[i][j] = D[i - 1][j];
            if (j - W[i] >= 0)
            {
                if (i - 1 >= 0)
                    D[i][j] = max(D[i][j], D[i][j - W[i]] + V[i]);
                else
                    D[i][j] = V[i];
            }
        }
    }
    cout << D[N-1][K];
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