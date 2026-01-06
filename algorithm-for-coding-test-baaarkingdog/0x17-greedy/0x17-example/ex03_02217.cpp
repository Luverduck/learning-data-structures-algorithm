#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2217
 */

int N;
int w[100001];

void greedy()
{
    sort(w, w + N, greater<>());
    int res = 0;
    for (int i = 1; i < N; ++i)
        res = max(res, w[i] * (i + 1));
    cout << res;
}

void solution()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> w[i];
    greedy();
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