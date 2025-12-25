#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/9663
 */

// 입력 N, 결과 res
int N, res = 0;
// 열에 대한 퀸의 점유 상태
bool isused1[16];
// 우상향 대각선에 대한 퀸의 점유 상태
bool isused2[31];
// 우하향 대각선에 대한 퀸의 점유 상태
bool isused3[31];

// r번째 퀸을 배치
void backtracking(int r)
{
    // 모든 퀸을 배치한 경우 (1행부터 N행까지 모든 행에 퀸을 배치한 경우)
    if (r == N)
    {
        // 가능한 경우의 수로 카운트
        res++;
        return;
    }
    // 현재 상태에서 가능한 모든 상태 후보군에 대하여 탐색 진행
    for (int c = 0; c < N; ++c)
    {
        // c열에 퀸을 배치할 때
        // 열, 우상향 대각선, 우하향 대각선 중 하나라도 점유하게 될 경우 다음 자식 노드 탐색
        if (isused1[c] || isused2[r + c] || isused3[r - c + N - 1]) continue;
        // c열 선택
        isused1[c] = true;
        isused2[r + c] = true;
        isused3[r - c + N - 1] = true;
        // r+1번째 퀸 배치 수행
        backtracking(r + 1);
        // 다음 탐색을 위해 c열 선택 취소
        isused1[c] = false;
        isused2[r + c] = false;
        isused3[r - c + N - 1] = false;
    }
}

void solution()
{
    cin >> N;
    // 백트래킹 시작 (초기에 선택된 숫자는 0개)
    backtracking(0);
    cout << res;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}