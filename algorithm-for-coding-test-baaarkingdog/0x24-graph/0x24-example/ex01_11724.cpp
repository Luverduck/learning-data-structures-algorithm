#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11724
 */

vector<int> adj[1005];
bool vis[1005];

void solution()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int p, q;
        cin >> p >> q;
        adj[p].emplace_back(q);
        adj[q].emplace_back(p);
    }

    int res = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (vis[i]) continue;
        res++;
        queue<int> que;
        que.push(i);
        vis[i] = true;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            for (int& nxt : adj[cur])
            {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                que.push(nxt);
            }
        }
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