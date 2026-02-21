#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1351
 */

using ll = long long;

ll N, P, Q;
map<ll, ll> A;

ll go(ll x)
{
    if (A[x] != 0) return A[x];
    if (x == 0) return A[x] = 1;
    return A[x] = go(x / P) + go(x / Q);
}

void solution()
{
    cin >> N >> P >> Q;
    cout << go(N);
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}