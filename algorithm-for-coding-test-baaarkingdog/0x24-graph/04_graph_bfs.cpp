#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 정점의 방문 상태를 저장하는 배열
bool vis[10];

// 그래프의 너비 우선 탐색
void bfs()
{
    // 다음 방문할 정점을 저장하는 큐
    queue<int> que;
    // 시작 정점을 큐에 넣고 방문 표시를 남김
    que.push(1);
    vis[1] = true;
    // 큐가 비어있을 때까지 반복
    while (!que.empty())
    {
        // 큐에서 정점을 꺼냄
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt : adj[cur])
        {
            // 이미 방문한 정점일 경우 건너뜀
            if (vis[nxt]) continue;
            // 큐에 다음 방문할 정점 넣음
            que.push(nxt);
            // 방문 표시
            vis[nxt] = true;
        }
    }
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    bfs();
}