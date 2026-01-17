#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/18870
 */

int N;
vector<int> pos, c_pos, tmp;

void solution()
{
    // 입력
    cin >> N;
    pos.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> pos[i];
        tmp.emplace_back(pos[i]);
    }

    // 중복 제거를 위한 정렬
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < N; ++i)
    {
        if (i == 0 || tmp[i] != tmp[i - 1])
            c_pos.emplace_back(tmp[i]);
    }

    // 이분 탐색을 통해 대상의 서수(Order) 출력
    for (int i = 0; i < N; ++i)
        cout << lower_bound(c_pos.begin(), c_pos.end(), pos[i]) - c_pos.begin() << " ";
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