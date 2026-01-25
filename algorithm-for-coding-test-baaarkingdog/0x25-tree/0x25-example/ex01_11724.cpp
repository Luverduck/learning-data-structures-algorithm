#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11725
 */

// 인접 리스트
vector<int> adj[100001];
// 각 정점의 부모 정점을 저장할 배열
int p[100001];

void bfs()
{
    queue<int> que;
    que.emplace(1);
    p[1] = 1;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        for (int& nxt : adj[cur])
        {
            if (p[cur] == nxt) continue;
            que.emplace(nxt);
            p[nxt] = cur;
        }
    }
}

void solution()
{
    // 입력 및 인접 리스트 초기화
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    // 너비 우선 탐색을 통해 부모 정점 배열 초기화
    bfs();
    // 부모 노드 출력
    for (int i = 2; i <= N; ++i) cout << p[i] << "\n";
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