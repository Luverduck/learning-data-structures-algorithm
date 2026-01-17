#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2230
 */

int N, M, R = 0x7fffffff;
int A[100001];

void solution()
{
    // 입력값
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];
    // 탐색을 위한 정렬
    sort(A, A + N);
    // 두 개의 포인터 st, en을 통해 탐색 진행
    int en = 0;
    for (int st = 0; st < N; ++st)
    {
        // A[en] - A[st]가 M 이상일 때까지 en의 값 증가
        while (en < N && A[en] - A[st] < M) en++;
        // en이 범위를 벗어날 경우 탐색 종료
        if (en == N) break;
        // R을 현재 R와 A[en] - A[st] 중 최소값으로 갱신
        R = min(R, A[en] - A[st]);
    }
    // 출력
    cout << R;
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