#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1920
 */

int N, M;
vector<int> v;

void solution()
{
    // 입력
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    // 이분 탐색을 위한 정렬
    sort(v.begin(), v.end());

    // 이분 탐색
    cin >> M;
    while (M--)
    {
        int target;
        cin >> target;
        cout << binary_search(v.begin(), v.end(), target) << "\n";
    }
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