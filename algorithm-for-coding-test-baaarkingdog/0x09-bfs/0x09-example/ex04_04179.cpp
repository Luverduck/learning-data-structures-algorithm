#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/4179
 */

// 미로의 상태를 저장할 배열
string board[1002];
// 미로의 각 위치에 불이 도달하는 시간 배열
int dist1[1002][1002];
// 미로의 각 위치에 지훈이가 도달하는 시간 배열
int dist2[1002][1002];
// 불이 도달한 위치를 저장하기 위한 queue
queue<pair<int, int>> q1;
// 지훈이가 도달한 위치를 저장하기 위한 queue
queue<pair<int, int>> q2;
// 4방향 탐색을 위한 x, y 좌표 보정값 배열
int dx[4] { 0, 1, 0, -1 };
int dy[4] { -1, 0, 1, 0 };

void solution()
{
    // 행 R, 열 C
    int R, C;
    cin >> R >> C;

    // 미로의 상태 배열 초기화
    for (int i = 0; i < R; ++i)
        cin >> board[i];

    // 미로의 각 위치에 대한 불, 지훈의 시간 배열 초기화
    for (int i = 0; i < R; ++i)
    {
        fill(dist1[i], dist1[i] + 1002, -1);
        fill(dist2[i], dist2[i] + 1002, -1);
    }

    // 미로의 각 위치에 대한 불, 지훈의 시간 배열에서
    // 불, 지훈의 초기 위치에 대한 시간 배열 요소의 값을 0으로 설정
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == 'F')
            {
                dist1[i][j] = 0;
                q1.emplace(i, j);
            }
            if (board[i][j] == 'J')
            {
                dist2[i][j] = 0;
                q2.emplace(i, j);
            }
        }
    }

    // 불에 대한 BFS
    while (!q1.empty())
    {
        // 현재 위치
        pair<int, int> cur = q1.front();
        q1.pop();
        // 현재 위치에 대하여 4방향 탐색
        for (int dir = 0; dir < 4; ++dir)
        {
            // 다음 탐색 위치
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 탐색 위치가 탐색 범위를 벗어날 경우 다음 방향 탐색
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            // 탐색 위치가 이미 탐색한 경우 또는 벽의 위치일 경우 다음 방향 탐색
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            // 탐색 위치의 시간 배열 요소 갱신
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            // 다음 탐색을 위해 탐색 위치를 queue에 저장
            q1.emplace(nx, ny);
        }
    }

    // 지훈에 대한 BFS
    while (!q2.empty())
    {
        // 현재 위치
        pair<int, int> cur = q2.front();
        q2.pop();
        // 현재 위치에 대하여 4방향 탐색
        for (int dir = 0; dir < 4; ++dir)
        {
            // 다음 탐색 위치
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 탐색 위치가 탐색 범위를 벗어날 경우 >> 탈출 성공
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                // 최초 탈출 시간 출력 후 종료
                cout << dist2[cur.first][cur.second] + 1;
                return;
            }
            // 탐색 위치가 이미 탐색한 경우 또는 벽의 위치일 경우 다음 방향 탐색
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            // 탐색 위치에 불보다 늦게 도달한 경우 다음 방향 탐색
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
            // 탐색 위치의 시간 배열 요소 갱신
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            // 다음 탐색을 위해 탐색 위치를 queue에 저장
            q2.emplace(nx, ny);
        }
    }
    // 탈출 실패
    cout << "IMPOSSIBLE";
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