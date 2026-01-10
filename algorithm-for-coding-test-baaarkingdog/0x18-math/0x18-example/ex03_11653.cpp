#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11653
 */

int N;

void factorization(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n != 1) cout << n;
}

void solution()
{
    cin >> N;
    factorization(N);
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