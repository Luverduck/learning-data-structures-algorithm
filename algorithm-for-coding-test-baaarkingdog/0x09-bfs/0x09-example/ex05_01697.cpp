#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1697
 */

// 수빈이가 각각의 위치에 도달하는 시간 배열
int dist[100002];
// 수빈이가 도달한 위치를 저장하기 위한 queue
queue<int> q;

void solution()
{
    // 수빈이의 위치 N, 동생의 위치 K
    int N, K;
    cin >> N >> K;

    // 각각의 위치에 대한 시간 배열 초기화
    fill(dist, dist + 100002, -1);

    // 수빈이의 초기 위치 저장
    q.emplace(N);
    // 수빈이의 초기 위치에 대한 시간 배열 요소의 값을 0으로 설정
    dist[N] = 0;

    // BFS 진행
    while (!q.empty())
    {
        // 현재 위치
        int cur = q.front();
        q.pop();
        // 현재 위치에 대하여 다음 탐색 위치 탐색
        for (int nxt : { cur + 1, cur - 1, cur * 2 })
        {
            // 탐색 위치가 탐색 범위를 벗어날 경우 다음 탐색 위치 탐색
            if (nxt < N || nxt >= 100000) continue;
            // 탐색 위치가 이미 탐색한 경우 다음 탐색 위치 탐색
            if (dist[nxt] != -1) continue;
            // 탐색 위치의 시간 배열 요소 갱신
            dist[nxt] = dist[cur] + 1;
            // 다음 탐색을 위해 탐색 위치를 queue에 저장
            q.emplace(nxt);
        }
    }
    // 결과 출력
    cout << dist[K];
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}