#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/9095
 */

int T, N;
int d[13];

void dp()
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= 12; ++i)
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
}

void solution()
{
    dp();
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << d[N] << "\n";
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