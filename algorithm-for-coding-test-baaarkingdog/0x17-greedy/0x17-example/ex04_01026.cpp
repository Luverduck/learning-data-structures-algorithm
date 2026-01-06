#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1026
 */

int N;
int A[51];
int B[51];

void greedy()
{
    sort(A, A + N);
    sort(B, B + N, greater<>());
    int res = 0;
    for (int i = 0; i < N; ++i) res += A[i] * B[i];
    cout << res;
}

void solution()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
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