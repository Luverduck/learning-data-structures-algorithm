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
    // 가장 가격이 높은 보석부터 확인하며
    // 해당 보석을 담을 수 있는 가방 중 최대 무게가 가장 작은 가방을 이용해 보석을 담는게 이득이다.

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> jewel[i].second >> jewel[i].first;
    sort(jewel, jewel + N);
    for (int i = 0; i < K; ++i)
    {
        int C;
        cin >> C;
        bags.emplace(C);
    }

    long long res = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        int M, V;
        tie(V, M) = jewel[i];
        auto iter = lower_bound(bags.begin(), bags.end(), M);
        if (iter == bags.end()) continue;
        res += V;
        bags.erase(iter);
    }
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