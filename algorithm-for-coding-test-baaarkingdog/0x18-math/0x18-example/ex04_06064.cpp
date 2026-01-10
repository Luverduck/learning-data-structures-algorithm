#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/6064
 */

// 최대 공약수
int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

// 최소 공배수
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

// <x, y>가 몇 번째 해인지 반환
int congruence(int M, int N, int x, int y)
{
    // x가 M일 경우 0으로 보정 (어떤 수를 M으로 나누었을 때 나머지로 0 ~ M-1 가능)
    if (x == M) x = 0;
    // y가 N일 경우 0으로 보정 (어떤 수를 N으로 나누었을 때 나머지로 0 ~ N-1 가능)
    if (y == N) y = 0;
    // 최소 공배수
    int l = lcm(M, N);
    // 나머지가 x인 수에서 시작하여 M씩 증가시키면서 해 탐색
    for (int i = x; i <= l; i += M)
    {
        // x == M, y == N일 경우에 0 반환에 대한 처리
        if (i == 0) continue;
        if (i % N == y) return i;
    }
    return -1;
}

void solution()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << congruence(M, N, x, y) << "\n";
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