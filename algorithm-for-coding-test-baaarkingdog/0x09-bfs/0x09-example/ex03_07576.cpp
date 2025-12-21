#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/7576
 */

// 상자의 상태를 저장할 배열
int board[1002][1002];
// 토마토 별로 익는 시간에 대한 배열
int dist[1002][1002];
// 익은 토마토의 위치를 저장할 queue
queue<pair<int, int>> q;
// 4방향 탐색을 위한 x, y 좌표 보정값 배열
int dx[4] { 0, 1, 0, -1 };
int dy[4] { -1, 0, 1, 0 };

void solution()
{
    // 가로 M, 세로 N
    int M, N;
    cin >> M >> N;

    // 상자의 상태 배열 초기화
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            // 안익은 토마토일 경우 시간 배열 요소를 -1로 설정
            if (board[i][j] == 0) dist[i][j] = -1;
            // 익은 토마토일 경우 queue에 저장
            if (board[i][j] == 1) q.emplace(i, j);
        }
    }

    // BFS 진행
    while (!q.empty())
    {
        // 현재 위치
        pair<int, int> cur = q.front();
        q.pop();
        // 현재 위치에 대하여 4방향 탐색
        for (int dir = 0; dir < 4; ++dir)
        {
            // 다음 탐색 위치
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 탐색 위치가 탐색 범위를 벗어날 경우 다음 방향 탐색
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // 이미 확인한 토마토일 경우 다음 방향 탐색
            if (dist[nx][ny] >= 0) continue;
            // 탐색 위치 토마토의 익는 시간을 현재 위치 토마토의 익는 시간에서 1만큼 큰 값 저장
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            // 익은 토마토 위치를 queue에 저장
            q.emplace(nx, ny);
        }
    }

    // 토마토가 모두 익을 때까지의 날짜 확인
    int res = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            // 안익은 토마토가 남아있는 경우 -1 출력
            if (dist[i][j] == -1)
            {
                cout << -1;
                return;
            }
            // 토마토가 모두 익을 때까지의 날짜 갱신
            res = max(res, dist[i][j]);
        }
    }
    // 결과 출력
    cout << res;
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