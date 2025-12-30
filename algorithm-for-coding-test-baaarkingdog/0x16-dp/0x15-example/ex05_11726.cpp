#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11726
 */

int N;
int d[1001];

void dp()
{
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= N; ++i)
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
}

void solution()
{
    cin >> N;
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