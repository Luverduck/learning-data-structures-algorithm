#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1654
 */

typedef long long ll;

ll K, N;
vector<ll> L;

void solution()
{
    // 입력
    cin >> K >> N;
    L.resize(K);
    for (int i = 0; i < K; ++i) cin >> L[i];

    // N개의 랜선을 만들 수 있는 랜선의 최대 길이 탐색 (최적화 문제)
    ll st = 1, en = (1LL << 31) - 1;
    while (st < en)
    {
        // 중간 길이
        ll mid = (st + en + 1) / 2;
        // 각각의 랜선을 중간 길이로 자를 때 랜선의 총 수
        ll cnt = 0;
        for (int i = 0; i < K; ++i) cnt += L[i] / mid;
        // 중간 길이로 각각의 랜선을 잘랐을 때 랜선의 총 수가 N개 이상인지 판정 (결정 문제)
        if (cnt < N) // 랜선의 총 수가 N보다 작을 경우 (길이가 너무 긴 경우)
            en = mid - 1; // 길이의 상한 감소
        else // 랜선의 총 수가 N보다 크거나 같을 경우 (길이가 딱 맞거나 넘치는 경우)
            st = mid; // 길이의 하한 증가
    }

    // 가능한 랜선의 최대 길이 출력
    cout << st;
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