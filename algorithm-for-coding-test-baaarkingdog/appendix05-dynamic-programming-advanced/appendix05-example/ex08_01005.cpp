#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1005
 */

int N, K, W;
int A[1005];
int D[1005];
vector<int> adj[100005];

// 위상 정렬 DP (Top-Down DP)
int go(int x)
{
    // 중복 계산 방지
    if (D[x] != -1) return D[x];
    // 초기화
    D[x] = 0;
    // 건설 시간이 가장 오래 걸리는 건물의 완공 시간 가산
    for (int nxt : adj[x])
        D[x] = max(D[x], go(nxt));
    // 건물 X의 건설 시간 가산
    D[x] += A[x];
    return D[x];
}

void solution()
{
    // 결과 테이블 초기화
    fill(D, D + 1001, -1);
    // 테스트케이스 별로 DP 수행
    int T;
    cin >> T;
    while (T--)
    {
        // 입력
        cin >> N >> K;
        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= K; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[v].emplace_back(u);
        }
        cin >> W;
        // 위상 정렬 DP (Top-Down DP)
        cout << go(W) << "\n";
        // 다음 수행을 위한 초기화
        fill(D, D + 1001, -1);
        for (int i = 1; i <= N; ++i) adj[i].clear();
    }
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