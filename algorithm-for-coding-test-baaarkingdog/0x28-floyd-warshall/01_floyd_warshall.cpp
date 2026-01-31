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
    }
    // 자기 자신으로 이동하는 경우에 대하여 인접 행렬 초기화
    for (int i = 1; i <= N; ++i) adj[i][i] = 0;
    // 정점 i에서 정점 j로 이동하는 최단 거리로 인접 행렬 갱신
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                // k번 정점을 거쳐서 이동하는 경우의 최단 거리와 비교하여 최소값으로 갱신
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
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