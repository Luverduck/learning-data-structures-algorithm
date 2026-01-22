#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1260
 */

int N, M, V;
vector<int> adj[1001];
bool vis[1001];

void bfs()
{
    queue<int> que;
    que.emplace(V);
    vis[V] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        for (int& nxt : adj[cur])
        {
            if (vis[nxt]) continue;
            que.emplace(nxt);
            vis[nxt] = true;
        }
    }
}

/*
void dfs()
{
    stack<int> stk;
    stk.emplace(V);
    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cout << cur << " ";
        for (int i = 0; i < adj[cur].size(); ++i)
        {
            int nxt = adj[cur][adj[cur].size() - 1 - i];
            if (vis[nxt]) continue;
            stk.push(nxt);
        }
    }
}
*/

void dfs(int cur)
{
    vis[cur] = true;
    cout << cur << " ";
    for (int& nxt : adj[cur])
    {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

void solution()
{
    cin >> N >> M >> V;
    for (int i = 0; i < M; ++i)
    {
        int p, q;
        cin >> p >> q;
        adj[p].emplace_back(q);
        adj[q].emplace_back(p);
    }

    for (int i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end());

    // dfs();
    dfs(V);
    cout << "\n";
    fill(vis, vis + N + 1, false);
    bfs();
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