#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1717
 */

int N, M;
vector<int> p(1000001, -1);

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
    cin >> N >> M;
    while (M--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0)
            uf_union(a, b);
        else
            cout << (uf_find(a) == uf_find(b) ? "YES" : "NO") << "\n";
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