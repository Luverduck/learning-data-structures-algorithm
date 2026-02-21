#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/12100
 */

// 크기 N
int N;
// 보드 상태 배열
int board[21][21];
// 임시 상태 배열
int board_tmp[21][21];

// 보드 회전
void RotateBoard()
{
    // 보드 상태 배열을 임시 배열에 저장
    int tmp[21][21];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tmp[i][j] = board_tmp[i][j];
    // 보드 회전 ( B[x][y] = A[r - 1 - y][x] )
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board_tmp[i][j] = tmp[N - 1 - j][i];
}

// 보드 왼쪽으로 기울이기
void TiltBoard(int dir)
{
    // 기울이기 방향이 왼쪽이 될 때까지 회전
    while (dir--) RotateBoard();
    // 임시 상태 배열의 모든 행에 대하여 기울이기
    for (int i = 0; i < N; ++i)
    {
        // 기울이기 결과 배열
        int tilted[21] { };
        // 블록 합치기 대상 요소의 인덱스
        int idx = 0;
        // 임시 상태 배열의 한 행 배열에 대하여 왼쪽으로 기울이기 진행
        for (int j = 0; j < N; ++j)
        {
            // 행 배열의 요소가 0일 경우 건너뜀
            if (board_tmp[i][j] == 0) continue;
            // 기울이기 결과 배열의 요소가 비어있을 경우
            if (tilted[idx] == 0)
                tilted[idx] = board_tmp[i][j];
            // 행 배열의 요소의 값이 기울이기 결과 배열의 요소와 같을 경우
            else if (tilted[idx] == board_tmp[i][j])
                tilted[idx++] *= 2; // 블록 합치기
            // 행 배열의 요소의 값이 기울이기 결과 배열의 요소와 다를 경우
            else
                tilted[++idx] = board_tmp[i][j]; // 다음 블록에 저장
        }
        // 기울이기 결과 배열을 임시 상태 배열의 해당 행에 복사
        for (int j = 0; j < N; ++j) board_tmp[i][j] = tilted[j];
    }
}

void solution()
{
    // 입력
    cin >> N;
    // 보드 상태 배열 초기화
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    // 5번 기울이기에서 가능한 모든 경우에 대하여 탐색
    int mx = 0;
    for (int state = 0; state < 1024; ++state)
    {
        // 보드 상태 배열을 임시 상태 배열에 복사
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board_tmp[i][j] = board[i][j];
        // 현재 상태에 대하여 5번 기울이기 진행
        int brute = state;
        for (int i = 0; i < 5; ++i)
        {
            int dir = brute % 4;
            brute /= 4;
            TiltBoard(dir);
        }
        // 5번 기울이기 후 가장 큰 블록의 값 갱신
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                mx = max(mx, board_tmp[i][j]);
    }
    // 출력
    cout << mx;
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