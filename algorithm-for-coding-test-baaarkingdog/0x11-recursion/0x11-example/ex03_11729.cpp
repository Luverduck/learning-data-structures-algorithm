#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11729
 */

void recur(int n, int src, int dest) {
    // n = 1일 경우
    // 원판을 src에서 dest로 이동
    if (n == 1)
    {
        cout << src << " " << dest << '\n';
        return;
    }
    // n = k일 경우
    // (k-1)개의 원판을 src에서 (6-src-dest)로 이동
    recur(n - 1, src, 6 - src - dest);
    // k번 원판을 src에서 dest로 이동
    cout << src << " " << dest << '\n';
    // (k-1)개의 원판을 (6-src-dest)에서 src로 이동
    recur(n - 1, 6 - src - dest, dest);
}

void solution()
{
    int K;
    cin >> K;
    cout << ((2 << K) - 1) << '\n';
    recur(K, 1, 3);
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