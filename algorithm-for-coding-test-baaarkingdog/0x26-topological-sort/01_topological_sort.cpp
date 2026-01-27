#include <bits/stdc++.h>

using namespace std;

// 정점의 수
int N;
// 인접 리스트
vector<int> adj[10];
// 각 정점의 진입 차수
int deg[10];
// 결과 벡터
vector<int> result;

void topological_sort()
{
    // 진입 차수가 0인 모든 정점을 큐에 저장
    queue<int> que;
    for (int i = 1; i <= N; ++i)
        if (deg[i] == 0) que.push(i);

    // 큐가 비어있을 때까지 반복
    while (!que.empty())
    {
        // 큐에서 정점을 꺼냄
        int cur = que.front();
        que.pop();
        // 꺼낸 정점을 결과 벡터에 저장
        result.emplace_back(cur);
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt :adj[cur])
        {
            // 인접한 정점의 진입 차수 감소
            deg[nxt]--;
            // 진입 차수가 0일 경우 큐에 저장
            if (deg[nxt] == 0) que.emplace(nxt);
        }
    }

    // 결과 출력
    if (result.size() != N)
    {
        cout << "cycle exists";
        return;
    }
    for (int& x : result) cout << x << " ";
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    topological_sort();
}