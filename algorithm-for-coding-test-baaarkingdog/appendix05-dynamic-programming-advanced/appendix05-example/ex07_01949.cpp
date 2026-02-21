#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1949
 */

int N;
int A[10005];
int D1[10005];
int D2[10005];

vector<int> adj[10005];

// DFS
void dfs(int cur, int par)
{
    D1[cur] = A[cur];
    D2[cur] = 0;
    for (int nxt : adj[cur])
    {
        if (nxt == par) continue;
        dfs(cur, nxt);
        D1[cur] += D2[nxt];
        D2[cur] += max(D1[nxt], D2[nxt]);
    }
}

void solution()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 0);
    cout << max(D1[1], D2[1]);
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