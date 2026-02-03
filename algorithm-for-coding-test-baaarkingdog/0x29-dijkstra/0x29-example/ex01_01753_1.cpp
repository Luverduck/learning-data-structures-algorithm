#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1753
 */

const int INF = 0x3f3f3f3f;

// 인접 리스트
vector<pair<int, int>> adj[20005];
// 정점의 최단 거리 확정 여부
bool fix[20005];
// 최단 거리 배열
int d[20005];
// 정점과 간선의 수, 시작 정점
int V, E, S;

void dijkstra_naive()
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
    // 시작 정점에 대한 최단 거리 초기화
    d[S] = 0;
    // 나머지 모든 정점에 대하여 탐색
    while (true)
    {
        // 최단 거리를 확정할 정점 탐색
        int idx = -1;
        for (int i = 1; i <= V; ++i)
        {
            // 최단 거리가 확정된 정점일 경우 건너뜀
            if (fix[i]) continue;
            // 거리가 가장 짧은 정점 선택
            if (idx == -1) idx = i;
            else if (d[i] < d[idx]) idx = i;
        }
        // 모든 정점의 최단 거리가 확정되었거나, 시작 정점에서 이동할 수 있는 정점이 없을 경우 종료
        if (idx == -1 || d[idx] == INF) break;
        // 해당 정점까지의 최단 거리 확정
        fix[idx] = true;
        // 시작 정점으로부터 해당 정점까지의 최단 거리 갱신
        for (auto& nxt : adj[idx])
            d[nxt.second] = min(d[nxt.second], d[idx] + nxt.first);
    }
}

void solution()
{
    dijkstra_naive();
    for (int i = 1; i <= V; ++i)
    {
        if (i == S) cout << "0";
        else if (d[i] == INF) cout << "INF";
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