#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1978
 */

bool is_prime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) return false;
    }
    return true;
}

void solution()
{
    int N, res = 0;
    cin >> N;
    while (N--)
    {
        int X;
        cin >> X;
        res += is_prime(X);
    }
    cout << res;
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