#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2178
 */

// 미로의 상태를 저장할 배열
int board[101][101];
// 시작점 (0, 0)으로부터의 거리(칸 수)를 저장할 배열
int dist[101][101];
// 방문한 위치를 저장할 queue
queue<pair<int, int>> q;
// 4방향 탐색을 위한 x, y 좌표 보정값 배열
int dx[4] { 0, 1, 0, -1 };
int dy[4] { -1, 0, 1, 0 };

void solution()
{
    // 행 N, 열 M
    int N, M;
    cin >> N >> M;

    // 미로의 상태 배열 초기화
    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j)
            board[i][j] = input[j] - '0';
    }

    // 거리 배열의 모든 요소를 -1(방문 안함)으로 설정
    for (int i = 0; i < N; ++i)
        fill(dist[i], dist[i] + M, -1);

    // 미로의 탐색 시작점 설정
    dist[0][0] = 1;
    q.emplace(0, 0);

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
            // 탐색 위치가 이미 탐색한 경우 또는 벽의 위치일 경우 다음 방향 탐색
            if (dist[nx][ny] != -1 || board[nx][ny] != 1) continue;
            // 탐색 위치의 거리 배열 요소에 현재 위치의 거리에서 1만큼 큰 값 저장
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            // 방문 위치를 queue에 저장
            q.emplace(nx, ny);
        }
    }
    // 결과 출력
    cout << dist[N - 1][M - 1];
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