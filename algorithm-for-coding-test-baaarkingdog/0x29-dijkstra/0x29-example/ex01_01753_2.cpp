#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1753
 */

const int INF = 0x3f3f3f3f;

// 인접 리스트 - { 비용, 정점 }
vector<pair<int, int>> adj[20005];
// 최단 거리 배열
int d[20005];
// 정점과 간선의 수, 시작 정점
int V, E, S;

void dijkstra()
{
    // 입력
    // 정점의 수, 간선의 수, 시작 정점
    cin >> V >> E >> S;
    // 최단 거리 배열 초기화
    fill(d, d + V + 1, INF);
    // 인접 리스트 초기화
    while (E--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].emplace_back(cost, v);
    }
    // 인접한 정점을 저장하기 위한 우선순위 큐 - { 비용, 정점 }
    priority_queue< pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>> > pq;
    // 시작 정점에 대한 최단 거리 초기화
    d[S] = 0;
    // 우선순위 큐에 시작 정점 저장
    pq.emplace(d[S], S);
    // 우선순위 큐가 비어있을 때까지 반복
    while (!pq.empty())
    {
        // 우선순위 큐에서 거리가 가장 짧은 정점 꺼냄
        auto cur = pq.top();
        pq.pop();
        // 정점의 거리가 최단 거리 배열 요소의 값과 다를 경우 건너뜀 (버리기)
        if (d[cur.second] != cur.first) continue;
        // 해당 정점과 연결된 간선에 대하여
        for (auto& nxt : adj[cur.second])
        {
            // 최단 거리 테이블 요소의 값과
            // 간선으로 연결된 인접 정점을 거쳐서 이동하는 경우의 최단 거리를 비교하여 인접 행렬 갱신
            if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.emplace(d[nxt.second], nxt.second);
        }
    }
}

void solution()
{
    dijkstra();
    for (int i = 1; i <= V; ++i)
    {
        if (d[i] == INF) cout << "INF";
        else cout << d[i];
        cout << "\n";
    }
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