#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1926
 */

// 그림의 상태를 저장할 배열
int board[502][502];
// 방문 여부를 저장할 배열
bool vis[502][502];
// 방문한 위치를 저장할 queue
queue<pair<int, int>> q;
// 4방향 탐색을 위한 x, y 좌표 보정값 배열
int dx[4] { 0, 1, 0, -1 };
int dy[4] { -1, 0, 1, 0 };

void solution()
{
    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;

    // 그림의 상태 배열 초기화
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    // 그림의 수
    int cnt = 0;
    // 그림의 최대 면적
    int max_area = 0;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(board[i][j] == 0 || vis[i][j]) continue;

            // 그림의 탐색 시작 위치에 방문 표시
            vis[i][j] = true;
            // 방문 위치를 queue에 저장
            q.emplace(i, j);

            // 그림의 수 증가
            cnt++;
            // 그림 면적 초기화
            int cur_area = 1;

            // BFS 진행
            while(!q.empty())
            {
                // 현재 위치
                pair<int, int> cur = q.front();
                q.pop();
                // 현재 위치에 대하여 4방향 탐색
                for(int dir = 0; dir < 4; ++dir)
                {
                    // 다음 탐색 위치
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    // 탐색 위치가 탐색 범위를 벗어날 경우 다음 방향 탐색
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    // 탐색 위치가 이미 탐색한 경우 또는 벽의 위치일 경우 다음 방향 탐색
                    if(vis[nx][ny] == true || board[nx][ny] != 1) continue;
                    // 탐색 위치에 방문 표시
                    vis[nx][ny] = true;
                    // 방문 위치를 queue에 저장
                    q.emplace(nx, ny);
                    // 그림의 면적 증가
                    cur_area++;
                }
            }
            // 그림의 최대 면적 갱신
            max_area = max(max_area, cur_area);
        }
    }
    // 결과 출력
    cout << cnt << '\n' << max_area;
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