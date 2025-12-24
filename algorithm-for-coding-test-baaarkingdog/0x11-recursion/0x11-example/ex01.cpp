#include <bits/stdc++.h>

using namespace std;

/**
 *  문제 1.
 *  a^b mod m
 */

int func1(long long a, long long b, long long m) {
    int val = 1;
    // 1에 a를 b번 곱한 후 나머지만 저장
    while (b--)
        val = val * a % m;
    return val;
}

void solution() {
    cout << func1(9, 2, 4);
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