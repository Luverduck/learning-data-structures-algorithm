#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1202
 */

int N, K;
pair<int, int> jewel[300001];
multiset<int> bags;

void solution()
{
    // 입력
    cin >> N >> K;
    // 보석에 대한 입력
    for (int i = 0; i < N; ++i)
        cin >> jewel[i].second >> jewel[i].first;
    // 보석을 가치 순으로 정렬
    sort(jewel, jewel + N);
    // 가방에 대한 입력
    for (int i = 0; i < K; ++i)
    {
        int C;
        cin >> C;
        bags.emplace(C);
    }
    // 가치가 높은 보석부터 가방에 넣기
    long long res = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        int M, V;
        tie(V, M) = jewel[i];
        // 최대 허용 무게가 M 이상인 가방 찾기
        auto iter = bags.lower_bound(M);
        if (iter == bags.end()) continue;
        // 보석의 전체 가치 갱신
        res += V;
        // 보석을 담은 가방 제거
        bags.erase(iter);
    }
    // 출력
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