#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1806
 */

int N, S, R = 0x7fffffff;
int A[100001];

void solution()
{
    // 입력값
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> A[i];
    // 부분합
    int tot = A[0];
    // 두 개의 포인터 st, en을 통해 탐색 진행
    int en = 0;
    for (int st = 0; st < N; ++st)
    {
        // 부분합이 S 이상일 때까지 en 증가
        while (en < N && tot < S)
        {
            en++;
            // en번째 요소를 부분합에 가산
            if (en != N) tot += A[en];
        }
        // en이 범위를 벗어날 경우 탐색 종료
        if (en == N) break;
        // R를 현재 R와 st - en + 1 중 최소값으로 갱신
        R = min(R, en - st + 1);
        // 다음 st 탐색을 위해 현재 st번째 요소를 부분합에서 감산
        tot -= A[st];
    }
    // 출력
    cout << (R != 0x7fffffff ? R : 0);
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