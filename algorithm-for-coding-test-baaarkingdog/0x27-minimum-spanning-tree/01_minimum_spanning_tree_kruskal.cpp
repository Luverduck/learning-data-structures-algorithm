#include <bits/stdc++.h>

using namespace std;

// 정점과 간선의 수
int V, E;
// {비용, 정점1, 정점2}
tuple<int, int, int> edge[100005];

vector<int> p(100005, -1);

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    else p[u] = v;
    return true;
}

void kruskal()
{
    sort(edge, edge + E);

    int cnt = 0;
    for (int i = 0; i < E; ++i)
    {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        cout << cost << " " << a << " " << b << "\n";
        cnt++;
        if (cnt == V - 1) break;
    }
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    kruskal();
}