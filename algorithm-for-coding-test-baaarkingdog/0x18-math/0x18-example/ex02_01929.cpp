#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1929
 */

int M, N;
vector<bool> state(1000001, true);

void sieve()
{
    state[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (!state[i]) continue;
        for (int j = i * i; j <= N; j += i)
        {
            state[j] = false;
        }
    }
}

void solution()
{
    cin >> M >> N;
    sieve();
    for (int i = M; i <= N; ++i)
    {
        if (state[i]) cout << i << "\n";
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