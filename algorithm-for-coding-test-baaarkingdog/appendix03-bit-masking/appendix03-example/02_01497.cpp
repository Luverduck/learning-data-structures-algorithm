#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1497
 */

int N, M;
long long state[10];

int bit_cnt(long long x)
{
    int ret = 0;
    for (int i = 0; i < max(N, M); ++i)
        ret += (x >> i) & 1;
    return ret;
}

void solution()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string name, list;
        cin >> name >> list;
        // i번 기타의 연주 가능 곡 상태값 갱신
        for (int j = M - 1; j >= 0; --j)
        {
            // 연주 가능 곡에 대한 비트 값을 1로 갱신
            state[i] = (state[i] << 1) | (list[j] == 'Y');
        }
    }

    // { 연주 가능 곡의 수, 필요한 기타의 수 }
    pair<int, int> res = { 0, -1 };
    // 가능한 모든 기타 조합에 대하여 탐색
    for (int tmp = 0; tmp < (1 << N); ++tmp)
    {
        // 기타 조합으로 연주 가능 곡 상태값을 비트 단위로 계산
        long long comb = 0;
        for (int i = 0; i < N; ++i)
        {
            if ((tmp & (1LL << i)) == 0) continue;
            // i번 기타 사용 시
            // 연주 가능 곡 상태값에 i번 기타의 연주 가능 곡 상태값을 비트 OR 연산
            comb |= state[i];
        }
        // 연주 가능 곡 수 (연주 가능 곡 상태값에서 값이 1인 비트 수 계산)
        int song_num = bit_cnt(comb);
        // 사용 기타 수 (기타 조합 상태값에서 값이 1인 비트 수 계산)
        int guitar_num = bit_cnt(tmp);
        if (res.first < song_num)
            res = { song_num, guitar_num };
        else if (res.first == song_num && res.second > guitar_num)
            res = { song_num, guitar_num };
    }
    cout << res.second;
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