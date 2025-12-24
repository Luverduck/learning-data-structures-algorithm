#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1629
 * 힌트
 * 1) a^n * a^n = a^2n
 * 2) 12^58 = 4(mod 67) >> 12^116 = 16(mod 67)
 */

int recur(long long a, long long b, long long c)
{
    // b = 1일 경우
    if (b == 1) return a % c;
    // b = B일 경우
    // (A mod B) % C는 (A mod B/2)^2 % C와 동일
    long long val = recur(a, b / 2, c);
    val = val * val % c;
    // B가 홀수일 경우에 대한 처리
    if (b % 2 == 0) return val;
    return val * a % c;
}

void solution()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << recur(A, B, C);
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