#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11728
 */

int N, M;
int a[1000001], b[1000001], c[20000002];

void solution()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < M; ++i) cin >> b[i];

    int a_idx = 0, b_idx = 0;
    for (int i = 0; i < N + M; ++i)
    {
        if (a_idx == N) c[i] = b[b_idx++];
        else if (b_idx == M) c[i] = a[a_idx++];
        else if (a[a_idx] < b[b_idx]) c[i] = a[a_idx++];
        else c[i] = b[b_idx++];
    }

    for (int i = 0; i < N + M; ++i) cout << c[i] << ' ';
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