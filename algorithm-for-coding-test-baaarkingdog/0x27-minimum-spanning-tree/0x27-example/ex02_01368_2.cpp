#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1368
 */

// 정점의 수 (가상의 정점 제외)
int N;
// { 비용, 정점 }
vector<pair<int, int>> adj[305];
// 각각의 정점이 최소 신장 트리에 포함되어있는지 여부
bool chk[305];

void solution()
{
    // 입력
    cin >> N;
    // 가상의 정점에 대한 인접 리스트 초기화
    for (int i = 1; i <= N; ++i)
    {
        int cost;
        cin >> cost;
        adj[0].emplace_back(cost, i);
        adj[i].emplace_back(cost, 0);
    }
    // 인접 리스트 초기화
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int cost;
            cin >> cost;
            if (i >= j) continue;
            adj[i].emplace_back(cost, j);
            adj[j].emplace_back(cost, i);
        }
    }
    // 선택된 간선의 수
    int cnt = 0;
    // 최소 신장 트리의 가중치
    int total_cost = 0;
    // 각각의 간선을 저장할 우선순위 큐 - { 비용, 정점1, 정점2 }
    priority_queue< tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>> > pq;
    // 1번 정점 선택 및 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가
    chk[1] = true;
    for (auto& nxt : adj[1])
        pq.emplace(nxt.first, 1, nxt.second);
    // 선택된 간선의 수가 정점의 수 - 1 개가 될 때까지 반복
    while (cnt < N)
    {
        // 우선순위 큐에서 비용이 가장 작은 간선 꺼냄
        int a, b, cost;
        tie(cost, a, b) = pq.top();
        pq.pop();
        // 꺼낸 간선이 최소 신장 트리에 포함된 두 정점을 연결하는 경우 건너뜀
        if (chk[b]) continue;
        // 꺼낸 간선이 최소 신장 트리에 포함된 정점 a와 포함되지 않은 b를 연결하는 경우
        // 해당 간선과 정점 b를 최소 신장 트리에 추가
        chk[b] = true;
        cnt++;
        // 최소 신장 트리의 가중치 갱신
        total_cost += cost;
        // 선택된 정점 b에 연결된 모든 간선에 대하여
        for (auto& nxt : adj[b])
            // 해당 간선이 정점 b와 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선일 경우
            if (!chk[nxt.second])
                // 해당 간선을 우선순위 큐에 추가
                pq.emplace(nxt.first, b, nxt.second);
    }
    // 출력
    cout << total_cost;
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