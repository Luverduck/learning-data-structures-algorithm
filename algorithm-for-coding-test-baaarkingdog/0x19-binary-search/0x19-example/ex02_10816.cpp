#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/10816
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

    // 이분 탐색을 통해 입력에서 탐색 대상이 포함된 개수 출력
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int target;
        cin >> target;
        // 탐색 대상의 개수 = 탐색 대상이 아닌 요소가 처음으로 등장하는 위치 - 탐색 대상이 처음 등장하는 위치
        cout << upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target) << " ";
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