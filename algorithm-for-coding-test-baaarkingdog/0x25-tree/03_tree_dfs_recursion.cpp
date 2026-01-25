#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 각 정점의 부모 정점을 저장할 배열
int p[10];
// 각 정점의 깊이
int depth[10];

// 트리의 깊이 우선 탐색
void dfs(int cur)
{
    cout << cur << " ";
    for (int nxt : adj[cur])
    {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    dfs(1);
}