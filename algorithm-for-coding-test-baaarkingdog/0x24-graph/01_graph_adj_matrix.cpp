#include <bits/stdc++.h>

using namespace std;

// 무방향 그래프 (Undirected Graph)
void undirected_graph()
{
    // 인접 행렬
    int adj_matrix[10][10] { };
    // 정점 수, 간선 수
    int v, e;
    cin >> v >> e;
    // 인접 행렬 초기화
    for (int i = 0; i < e; ++i)
    {
        int p, q;
        cin >> p >> q;
        // 정점 p와 정점 q를 연결하는 간선
        adj_matrix[p][q] = 1;
        // 정점 q와 정점 p를 연결하는 간선
        adj_matrix[p][q] = 1;
    }
}

// 방향 그래프 (Directed Graph)
void directed_graph()
{
    // 인접 행렬
    int adj_matrix[10][10] { };
    // 정점 수, 간선 수
    int v, e;
    cin >> v >> e;
    // 인접 행렬 초기화
    for (int i = 0; i < e; ++i)
    {
        int p, q;
        cin >> p >> q;
        // 정점 p에서 정점 q로 향하는 간선
        adj_matrix[p][q] = 1;
    }
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    undirected_graph();
    directed_graph();
}