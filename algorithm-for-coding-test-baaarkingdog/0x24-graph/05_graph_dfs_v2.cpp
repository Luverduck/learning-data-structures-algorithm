#include <bits/stdc++.h>

using namespace std;

// 인접 리스트
vector<int> adj[10];
// 정점의 방문 상태를 저장하는 배열
bool vis[10];

// 그래프의 깊이 우선 탐색
void dfs()
{
    // 다음 방문할 정점을 저장하는 스택
    stack<int> stk;
    // 시작 정점을 스택에 넣음
    stk.push(1);
    // 스택이 비어있을 때까지 반복
    while (!stk.empty())
    {
        // 스택에서 정점을 꺼냄
        int cur = stk.top();
        stk.pop();
        // 이미 방문한 정점일 경우 건너뜀
        if (vis[cur]) continue;
        // 방문 표시
        vis[cur] = true;
        cout << cur << " ";
        // 꺼낸 정점과 인접한 모든 정점 탐색
        for (int& nxt : adj[cur])
        {
            // 이미 방문한 정점일 경우 건너뜀
            if (vis[nxt]) continue;
            // 스택에 다음 방문할 정점 넣음
            stk.push(nxt);
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
    dfs();
}