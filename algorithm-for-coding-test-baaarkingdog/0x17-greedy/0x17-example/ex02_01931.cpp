#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1931
 */

int N, t;
vector<pair<int, int>> v;

void greedy()
{
    int res = 0;
    for (auto& p : v)
    {
        if (p.first < t) continue;
        res++;
        t = p.second;
    }
    cout << res;
}

void solution()
{
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](auto& a, auto& b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    greedy();
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