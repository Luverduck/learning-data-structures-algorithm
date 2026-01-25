#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 각 정점의 부모 정점을 저장할 배열
int p[10];
// 각 정점의 깊이
int depth[10];

// 트리의 너비 우선 탐색
void bfs(int root)
{
    // 다음 방문할 정점을 저장하는 큐
    queue<int> que;
    // 루트 정점을 큐에 저장
    que.push(root);
    // 큐가 비어있을 때까지 반복
    while (!que.empty())
    {
        // 큐에서 정점을 꺼냄
        int cur = que.front();
        que.pop();
        cout << cur;
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt : adj[cur])
        {
            // 인접한 정점이 부모 정점일 경우 건너뜀
            if (p[cur] == nxt) continue;
            // 큐에 다음 방문할 정점으로 해당 자식 정점 저장
            que.push(nxt);
            // 해당 자식 정점의 부모 정점으로 저장
            p[nxt] = cur;
            // 자식 정점의 깊이를 부모 정점의 깊이 + 1로 초기화
            depth[nxt] = depth[cur] + 1;
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
    bfs(1);
}