#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/7511
 */

int T, N, K, M;

vector<int> p(1000005, -1);

int uf_find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = uf_find(p[x]);
}

bool uf_union(int u, int v)
{
    u = uf_find(u);
    v = uf_find(v);
    if (u == v) return false;
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

void solution()
{
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> N;
        fill(p.begin(), p.end(), -1);
        cin >> K;
        while (K--)
        {
            int a, b;
            cin >> a >> b;
            uf_union(a, b);
        }
        cin >> M;
        cout << "Scenario " << i << ":\n";
        while (M--)
        {
            int u, v;
            cin >> u >> v;
            cout << (uf_find(u) == uf_find(v)) << "\n";
        }
        cout << "\n";
    }
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