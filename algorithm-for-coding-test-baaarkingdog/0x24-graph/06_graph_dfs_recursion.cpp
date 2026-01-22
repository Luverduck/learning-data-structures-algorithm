#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 정점의 방문 상태를 저장하는 배열
bool vis[10];

// 그래프의 깊이 우선 탐색 (재귀 호출)
void dfs(int cur)
{
    // 방문 표시
    vis[cur] = true;
    cout << cur << " ";
    // 방문한 정점과 인접한 모든 정점 탐색
    for (int& nxt : adj[cur])
    {
        // 이미 방문한 정점일 경우 건너뜀
        if (vis[nxt]) continue;
        // 깊이 우선 탐색 진행
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