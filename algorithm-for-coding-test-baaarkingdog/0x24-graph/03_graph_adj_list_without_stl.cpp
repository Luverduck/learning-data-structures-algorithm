#include <bits/stdc++.h>

using namespace std;

// 무방향 그래프 (Undirected Graph)
void undirected_graph()
{
    // 간선 정보 (간선으로 연결된 두 정점 정보)
    int edge[10][2] { };
    // 정점의 차수
    int deg[10] { };
    // 인접 리스트 배열
    int* adj_list[10] { };
    // 인접 리스트 배열의 각각의 리스트에 저장된 요소의 수
    int idx[10] { };
    // 정점 수, 간선 수
    int v, e;
    cin >> v >> e;
    // 간선 정보 초기화
    for (int i = 0; i < e; ++i)
    {
        // 간선 정보 초기화 (p -> q)
        cin >> edge[i][0] >> edge[i][1];
        // 정점 p의 진출 차수 갱신
        deg[edge[i][0]]++;
    }
    // 인접 리스트 배열 생성
    for (int i = 1; i <= v; ++i)
        adj_list[i] = new int[deg[i]];
    // 인접 리스트 배열 초기화
    for (int i = 0; i < e; ++i)
    {
        // p번 정점
        int p = edge[i][0];
        // q번 정점
        int q = edge[i][1];
        // p번째 인접 리스트의 idx[p]번째 요소에 q 저장
        adj_list[p][idx[p]] = q;
        // idx[p] 증가
        idx[p]++;
        // q번째 인접 리스트의 idx[q]번째 요소에 p 저장
        adj_list[q][idx[q]] = p;
        // idx[q] 증가
        idx[q]++;
    }
}

// 방향 그래프 (Directed Graph)
void directed_graph()
{
    // 간선 정보 (간선으로 연결된 두 정점 정보)
    int edge[10][2] { };
    // 정점의 진출 차수
    int deg[10] { };
    // 인접 리스트 배열
    int* adj_list[10] { };
    // 인접 리스트 배열의 각각의 리스트에 저장된 요소의 수
    int idx[10] { };
    // 정점 수, 간선 수
    int v, e;
    cin >> v >> e;
    // 간선 정보 초기화
    for (int i = 0; i < e; ++i)
    {
        // 간선 정보 초기화 (p -> q)
        cin >> edge[i][0] >> edge[i][1];
        // 정점 p의 진출 차수 갱신
        deg[edge[i][0]]++;
    }
    // 인접 리스트 배열 생성
    for (int i = 1; i <= v; ++i)
        adj_list[i] = new int[deg[i]];
    // 인접 리스트 배열 초기화
    for (int i = 0; i < e; ++i)
    {
        // p번 정점
        int p = edge[i][0];
        // q번 정점
        int q = edge[i][1];
        // p번 인접 리스트의 idx[p]번째 요소에 q 저장
        adj_list[p][idx[p]] = q;
        // idx[p] 증가
        idx[p]++;
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