#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/9251
 */

string A, B;
int D[1005][1005];

void solution()
{
    cin >> A >> B;
    int M = A.length(), N = B.length();
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (A[i - 1] == B[j - 1])
                D[i][j] = D[i - 1][j - 1] + 1;
            D[i][j] = max({D[i][j], D[i - 1][j], D[i][j - 1]});
        }
    }
    cout << D[M][N];
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