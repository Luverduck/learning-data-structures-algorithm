#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2252
 */

int N, M;
vector<int> adj[32001];
int deg[32001];

void solution()
{
    // 입력
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].emplace_back(B);
        deg[B]++;
    }

    // 진입 차수가 0인 모든 정점을 큐에 저장
    queue<int> que;
    for (int i = 1; i <= N; ++i)
        if (deg[i] == 0) que.emplace(i);

    // 큐가 비어있을 때까지 반복
    while (!que.empty())
    {
        // 큐에서 정점을 꺼냄
        int cur = que.front();
        que.pop();
        // 꺼낸 정점 출력
        cout << cur << " ";
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt : adj[cur])
        {
            // 인접한 정점의 진입 차수 감소
            deg[nxt]--;
            // 진입 차수가 0일 경우 큐에 저장
            if (deg[nxt] == 0) que.emplace(nxt);
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
    solution();
}