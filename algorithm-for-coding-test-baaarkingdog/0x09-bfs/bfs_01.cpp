#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

// 탐색 가능 위치를 저장할 배열
int board[502][502];
// 방문 여부를 저장할 배열
bool vis[502][502];
// 탐색 방향 지정을 위한 x, y의 좌표 보정값 배열
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 탐색 범위 지정
    int n = 7, m = 10;

    // 방문한 좌표를 저장할 queue
    queue<pair<int, int>> q;
    // (0, 0)의 방문 여부를 1로 변경
    vis[0][0] = 1;
    // 방문한 위치를 queue에 저장
    q.emplace(0, 0);
    // queue가 비어있을 때까지 진행
    while (!q.empty())
    {
        // queue의 맨 앞에 저장된 좌표를 cur에 저장한 후 pop
        pair<int, int> cur = q.front();
        q.pop();
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";
        // 현재 좌표 cur에 대하여 4방향 탐색
        for (int dir = 0; dir < 4; ++dir)
        {
            // 방향 좌표 계산
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 방향 좌표가 탐색 범위를 벗어나면 다음 방향 탐색
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방향 좌표가 이미 방문한 좌표이거나 탐색할 수 없는 좌표일 경우 다음 방향 좌표 탐색
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            // 방향 좌표의 방문 여부를 1로 변경
            vis[nx][ny] = 1;
            // 방향 좌표를 queue에 저장
            q.emplace(nx, ny);
        }
    }
}