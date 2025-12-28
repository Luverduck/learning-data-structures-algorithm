#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11652
 */

int N;
long long arr[100001];

void solution()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);

    // 동일한 숫자의 등장 횟수
    int cnt = 0;
    // 가장 많이 등장한 숫자의 등장 횟수
    int max_cnt = 0;
    // 가장 많이 등장한 숫자
    long long max_val = -(1LL << 62) - 1;
    for (int i = 0; i < N; ++i)
    {
        // 0번째 회차이거나 이전 회차의 숫자와 동일한 숫자가 등장한 경우
        if (i == 0 || arr[i - 1] == arr[i]) cnt++;
        else // 이전 회차의 숫자와 다른 숫자가 등장한 경우
        {
            // 가장 많이 등장한 숫자와 그 등장 횟수 갱신
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                max_val = arr[i - 1];
            }
            // 등장 횟수를 1로 초기화
            cnt = 1;
        }
    }
    // 마지막 등장한 숫자에 대하여
    // 이전 회차의 숫자와 동일한 숫자만 등장한 채로 루프를 벗어난 경우에 대한 처리
    if (cnt > max_cnt) max_val = arr[N - 1];
    cout << max_val;
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