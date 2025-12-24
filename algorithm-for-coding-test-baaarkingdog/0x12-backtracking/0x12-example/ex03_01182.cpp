#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1182
 */

int N, S;
int arr[20];
int cnt;

// 공집합(N개의 원소가 전부 0인 경우)부터 자기자신(N개의 원소가 모두 포함된 경우)까지 모든 경우를 확인하여
// 부분 집합의 모든 원소의 합이 S인 경우에만 카운트
void backtracking(int cur, int tot)
{
    // N개의 원소를 모두 선택한 경우
    if (cur == N)
    {
        // 모든 원소의 합이 S와 같을 때 카운트
        if (tot == S) cnt++;
        return;
    }
    // 0을 원소로 선택 후 부분집합의 합 검사 (arr[cur]를 요소로 추가하지 않음)
    backtracking(cur + 1, tot);
    // arr[cur]을 원소로 선택 후 부분집합의 합 검사
    backtracking(cur + 1, tot + arr[cur]);
}

void solution()
{
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    backtracking(0, 0);
    // 크기가 0인 부분집합 제외
    if (S == 0) cnt--;
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