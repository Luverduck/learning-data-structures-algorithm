#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/18808
 */

// 노트북 세로 N, 가로 M, 스티커 수 K
int N, M, K;
// 노트북 상태 배열
int notebook[42][42];
// 모눈종이 행 R, 열 C
int R, C;
// 모눈종이 상태 배열
int paper[12][12];

// 스티커 붙이기
bool PasteSticker(int x, int y)
{
    // 영역에 스티커를 붙일 수 있는지 확인
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            // 노트북의 해당 영역에 이미 스티커가 붙어있는 경우
            if (notebook[x + i][y + j] == 1 && paper[i][j] == 1)
                return false; // false(스티커를 붙일 수 없음) 반환
    // 영역에 스티커 붙이기
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            // 노트북의 해당 영역 상태 갱신
            if (paper[i][j] == 1)
                notebook[x + i][y + j] = 1;
    // true(스티커를 붙임) 반환
    return true;
}

// 스티커 회전
void RotateSticker()
{
    // 스티커 상태 배열을 임시 배열에 저장
    int tmp[12][12];
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            tmp[i][j] = paper[i][j];
    // 스티커 회전 ( B[x][y] = A[r-1-y][x] )
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < R; ++j)
            paper[i][j] = tmp[R - 1 - j][i];
    // 행과 열을 맞바꿈
    swap(R, C);
}

void solution()
{
    // 입력
    cin >> N >> M >> K;
    // 스티커 붙이기
    while (K--)
    {
        // 스티커 상태 배열 초기화
        cin >> R >> C;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                cin >> paper[i][j];
            }
        }
        // 스티커를 4번 회전할 때까지 반복
        for (int rot = 0; rot < 4; ++rot)
        {
            // 스티커를 붙일 수 있는지 여부
            bool is_pasted = false;
            for (int x = 0; x <= N - R; ++x)
            {
                // 스티커를 붙일 수 있는 경우 종료
                if (is_pasted) break;
                for (int y = 0; y <= M - C; ++y)
                {
                    // 스티커를 붙일 수 있는 경우
                    if (PasteSticker(x, y))
                    {
                        // 스티커를 붙일 수 있는지 여부를 true로 변경
                        is_pasted = true;
                        break;
                    }
                }
            }
            // 스티커를 붙일 수 있는 경우 종료
            if (is_pasted) break;
            // 스티커 회전
            RotateSticker();
        }
    }
    // 노트북 영역 배열에서 스티커가 붙은 영역 계산
    int res = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            res += notebook[i][j];
        }
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