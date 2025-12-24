#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/9663
 */

int N, cnt = 0;
bool isused1[16];
bool isused2[31];
bool isused3[31];

// cur번째 행에 퀸을 배치할 예정
void backtracking(int cur)
{
    if (cur == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (isused1[i] || isused2[cur + i] || isused3[cur - i + N - 1]) continue;
        isused1[i] = true;
        isused2[cur + i] = true;
        isused3[cur - i + N - 1] = true;
        backtracking(cur + 1);
        isused1[i] = false;
        isused2[cur + i] = false;
        isused3[cur - i + N - 1] = false;
    }
}

void solution()
{
    cin >> N;
    // 백트래킹 시작 (초기에 선택된 숫자는 0개)
    backtracking(0);
    cout << cnt;
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