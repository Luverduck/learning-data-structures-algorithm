#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1463
 */

int d[1000001];
int N;

void dp()
{
    cin >> N;
    d[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }
}

void solution()
{
    dp();
    cout << d[N];
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