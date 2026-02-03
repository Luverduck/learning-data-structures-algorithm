#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11779
 */

const int INF = 0x3f3f3f3f;

// 인접 리스트 - { 비용, 정점 }
vector<pair<int, int>> adj[1005];
// 최단 거리 배열
int d[1005];
// 시작 정점에서 i번 정점으로 이동하는 최단 경로에서 i번 정점 방문 직전에 방문해야 하는 정점
int pre[1005];
// 정점과 간선의 수
int V, E;
// 시작 정점과 도착 정점
int st, en;

void dijkstra()
{
    // 입력
    // 정점과 간선의 수 초기화
    cin >> V >> E;
    // 최단 거리 배열 초기화
    fill(d, d + V + 1, INF);
    // 인접 리스트 초기화
    while (E--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].emplace_back(cost, v);
    }
    // 시작 정점과 도착 정점 초기화
    cin >> st >> en;
    // 인접한 정점을 저장하기 위한 우선순위 큐 - { 비용, 정점 }
    priority_queue< pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>> > pq;
    // 시작 정점에 대한 최단 거리 초기화
    d[st] = 0;
    // 우선순위 큐에 시작 정점 저장
    pq.emplace(d[st], st);
    // 우선순위 큐가 비어있을 때까지 반복
    while (!pq.empty())
    {
        // 우선순위 큐에서 거리가 가장 짧은 정점 꺼냄
        auto cur = pq.top();
        pq.pop();
        // 정점의 거리가 최단 거리 배열 요소의 값과 다를 경우 건너뜀 (버리기)
        if (d[cur.second] != cur.first) continue;
        // 해당 정점과 인접한 정점에 대하여
        for (auto& nxt : adj[cur.second])
        {
            // 최단 거리 테이블 요소의 값과
            // 간선으로 연결된 인접 정점을 거쳐서 이동하는 경우의 최단 거리를 비교하여 인접 행렬 갱신
            if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.emplace(d[nxt.second], nxt.second);
            // 인접 정점에 방문하기 전 방문해야 하는 정점으로 추가
            pre[nxt.second] = cur.second;
        }
    }
    // 시작 정점 st부터 도착 정점 en까지의 최단 거리
    cout << d[en] << "\n";
    // en -> st 방향으로 정점을 추가하여 최단 경로 복원
    vector<int> path;
    int cur = en;
    while (cur != st)
    {
        path.emplace_back(cur);
        cur = pre[cur];
    }
    path.emplace_back(cur);
    // st -> en 방향으로 정렬
    reverse(path.begin(), path.end());
    // 최단 경로에 포함된 정점의 수
    cout << path.size() << "\n";
    // 최단 경로 출력
    for (auto& x : path) cout << x << " ";
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    dijkstra();
}