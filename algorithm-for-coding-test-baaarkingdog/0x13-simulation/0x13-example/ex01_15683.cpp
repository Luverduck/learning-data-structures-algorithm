#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/15683
 */

// 세로 N, 가로 M
int N, M;
// 사무실 상태 배열
int board[10][10];
// 임시 상태 배열
int board_tmp[10][10];
// CCTV의 위치를 저장할 벡터
vector<pair<int, int>> cctv;
// 감시 방향 결정 배열
int dx[4] { 1, 0, -1, 0 };
int dy[4] { 0, 1, 0, -1 };

// 상태 배열의 영역을 벗어났는지 여부
bool IsOutOfBounds(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}

// 벽을 만날 때까지 이동하면서 지나가는 영역에 마킹
void MarkPosition(int x, int y, int dir)
{
    dir %= 4;
    // 감시 방향을 따라 마킹
    while (true)
    {
        // 감시 방향 결정
        x += dx[dir];
        y += dy[dir];
        // 임시 상태 배열의 영역을 벗어났거나 벽을 만났을 경우 종료
        if (IsOutOfBounds(x, y) || board_tmp[x][y] == 6) break;
        // 이미 마킹된 영역일 경우 건너뜀
        if (board_tmp[x][y] != 0) continue;
        // 지나간 영역을 0이 아닌 값(7)로 마킹
        board_tmp[x][y] = 7;
    }
}

void solution()
{
    // 입력
    cin >> N >> M;
    int res = 0;
    // 사무실 상태 배열 초기화
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
                cctv.emplace_back(i, j);
            if (board[i][j] == 0) res++;
        }
    }

    // CCTV의 감시 방향 조합에 대하여 탐색
    for (int state = 0; state < (1 << 2 * cctv.size()); ++state)
    {
        // 사무실 상태 배열를 임시 상태 배열에 복사
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                board_tmp[i][j] = board[i][j];
        }
        // 현재 CCTV의 감시 방향 조합에 대하여 탐색
        int brute = state;
        for (int i = 0; i < cctv.size(); ++i)
        {
            // 특정 CCTV의 감시 방향
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            // CCTV의 종류에 따라 영역 마킹 진행
            if (board[x][y] == 1)
            {
                MarkPosition(x, y, dir);
            }
            else if (board[x][y] == 2)
            {
                MarkPosition(x, y, dir);
                MarkPosition(x, y, dir + 2);
            }
            else if (board[x][y] == 3)
            {
                MarkPosition(x, y, dir);
                MarkPosition(x, y, dir + 1);
            }
            else if (board[x][y] == 4)
            {
                MarkPosition(x, y, dir);
                MarkPosition(x, y, dir + 1);
                MarkPosition(x, y, dir + 2);
            }
            else if (board[x][y] == 5)
            {
                MarkPosition(x, y, dir);
                MarkPosition(x, y, dir + 1);
                MarkPosition(x, y, dir + 2);
                MarkPosition(x, y, dir + 3);
            }
        }
        // 마킹이 없는 영역 수 계산
        int blind = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                blind += (board_tmp[i][j] == 0);
        }
        // 사각 지대의 최소값 갱신
        res = min(res, blind);
    }
    // 출력
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