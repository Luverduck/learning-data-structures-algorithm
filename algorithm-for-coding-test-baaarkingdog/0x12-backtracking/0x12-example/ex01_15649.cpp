#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/15649
 */

// 선택 가능한 가장 큰 자연수 N, 선택할 수 있는 자연수의 개수 M
int N, M;
// 선택된 자연수
int arr[10];
// 자연수 선택 여부
bool isused[10];

void backtracking(int k)
{
    // M개의 자연수가 모두 선택된 경우
    if (k == M)
    {
        // 출력
        for (int i = 0; i < M; ++i)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    // 1 ~ N까지 자연수 중 사용되지 않은 자연수 탐색
    for (int i = 0; i <= N; ++i)
    {
        if (!isused[i])
        {
            arr[k] = i;
            isused[i] = true;
            backtracking(k + 1);
            isused[i] = false;
        }
    }
}

void solution()
{
    cin >> N >> M;
    // 백트래킹 시작 (초기에 선택된 숫자는 0개)
    backtracking(0);
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