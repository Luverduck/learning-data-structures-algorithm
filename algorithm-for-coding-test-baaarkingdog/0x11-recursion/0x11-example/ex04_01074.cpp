#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1074
 */

int recur(int n, int r, int c) {
    // n = 0일 경우
    // 1x1 배열의 방문 순서 0 반환
    if (n == 0) return 0;
    // n = k일 경우
    // (2^k)x(2^k) 배열을 4등분한 영역 중 어떤 영역에 속하는지에 따라 결과 반환
    int half = 1 << (n - 1);
    if (r < half && c < half) return recur(n - 1, r, c);
    if (r < half) return half * half + recur(n - 1, r, c - half);
    if (c < half) return 2 * half * half + recur(n - 1, r - half, c);
    return 3 * half * half + recur(n - 1, r - half, c - half);
}

void solution()
{
    int N, R, C;
    cin >> N >> R >> C;
    cout << recur(N, R, C);
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