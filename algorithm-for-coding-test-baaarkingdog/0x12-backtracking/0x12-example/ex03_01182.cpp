#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1182
 */

// 입력 N, S
int N, S;
// 정수를 저장할 배열
int arr[20];
// 수열의 모든 원소의 합이 S가 되는 수열의 개수
int res;

// 부분집합의 합이 tot인 상태에서 cur번째 원소 선택
void backtracking(int cur, int tot)
{
    // N개의 원소를 모두 선택한 경우
    if (cur == N)
    {
        // 모든 원소의 합이 S와 같을 때 카운트
        if (tot == S) res++;
        return;
    }
    // arr[cur]을 원소로 선택하지 않았을 경우에 대한 부분집합의 합 검사
    backtracking(cur + 1, tot);
    // arr[cur]을 원소로 선택했을 경우에 대한 부분집합의 합 검사
    backtracking(cur + 1, tot + arr[cur]);
}

void solution()
{
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    backtracking(0, 0);
    // 크기가 0인 부분집합 제외
    if (S == 0) res--;
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