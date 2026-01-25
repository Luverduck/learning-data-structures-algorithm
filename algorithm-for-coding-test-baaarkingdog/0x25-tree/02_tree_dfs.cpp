#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 각 정점의 부모 정점을 저장할 배열
int p[10];
// 각 정점의 깊이
int depth[10];

// 트리의 깊이 우선 탐색
void dfs(int root)
{
    // 다음 방문할 정점을 저장하는 스택
    stack<int> stk;
    // 루트 정점을 스택에 저장
    stk.push(root);
    // 스택이 비어있을 때까지 반복
    while (!stk.empty())
    {
        // 스택에서 정점을 꺼냄
        int cur = stk.top();
        stk.pop();
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt : adj[cur])
        {
            // 인접한 정점이 부모 정점일 경우 건너뜀
            if (p[cur] == nxt) continue;
            // 스택에 다음 방문할 정점으로 해당 자식 정점 저장
            stk.push(nxt);
            // 해당 자식 정점의 부모 정점으로 저장
            p[nxt] = cur;
            // 자식 정점의 깊이를 부모 정점의 깊이 + 1로 초기화
            depth[nxt] = depth[cur] + 1;
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
    dfs(1);
}