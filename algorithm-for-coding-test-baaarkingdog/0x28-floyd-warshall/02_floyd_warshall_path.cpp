#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11404
 */

const int INF = 0x3f3f3f3f;

// 인접 행렬의 행, 열 수
int M, N;
// 인접 행렬
int adj[101][101];
// i번 정점에서 j번 정점으로 이동하는 최단 경로에서 i번 정점 다음으로 방문해야 하는 정점
int nxt[101][101];

void solution()
{
    // 입력
    cin >> M >> N;
    // 인접 행렬 초기화
    for (int i = 1; i <= N; ++i)
        fill(adj[i], adj[i] + N + 1, INF);
    // 다른 정점을 거치지 않고 이동하는 경우에 대하여 인접 행렬 초기화
    while (M--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u][v] = min(adj[u][v], cost);
        nxt[u][v] = v;
    }
    // 자기 자신으로 이동하는 경우에 대하여 인접 행렬 초기화
    for (int i = 1; i <= N; ++i) adj[i][i] = 0;
    // 정점 i에서 정점 j로 이동하는 최단 거리로 인접 행렬 갱신
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                // k번 정점을 거쳐서 이동하는 경우의 최단 거리와 비교하여 최소값으로 갱신
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    // i번 정점 다음 방문할 정점 갱신
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    // 경로 복원
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // 정점 i에서 정점 j로 이동할 수 없는 경우 0 출력
            if (adj[i][j] == 0 || adj[i][j] == INF)
            {
                cout << "0\n";
                continue;
            }
            // 정점 i에서 정점 j로 이동하는 최단 경로 복원
            vector<int> path;
            int st = i;
            while (st != j)
            {
                path.emplace_back(st);
                st = nxt[st][j];
            }
            // 정점 j까지 포함
            path.emplace_back(j);
            // 최단 경로의 길이
            cout << path.size() << " ";
            // 최단 경로를 구성하는 모든 정점 출력
            for (int& x : path) cout << x << " ";
            cout << "\n";
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