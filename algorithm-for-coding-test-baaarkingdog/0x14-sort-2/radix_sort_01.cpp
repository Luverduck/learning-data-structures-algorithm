#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
// 정렬되지 않은 요소들 중 가장 큰 요소의 자릿수
int d;
// 10의 거듭제곱을 저장할 벡터
vector<int> p10;
// 0~10까지 수를 나타내는 버킷
vector<int> bucket[10];

int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

void radix_sort()
{
    // 정렬되지 않은 요소들 중 가장 큰 요소
    int max_val = *max_element(arr, arr + N);
    // 가장 큰 요소의 자리수 계산
    d = to_string(max_val).length();
    // 가장 큰 요소의 자리수로 p10 크기 조정
    p10.resize(d);
    // p10 초기화 (10^0 ~ 10^d)
    p10[0] = 1;
    for (int i = 1; i < d; ++i) p10[i] = p10[i - 1] * 10;

    for (int i = 0; i < d; ++i)
    {
        // 버킷 비우기
        for (int j = 0; j < 10; ++j) bucket[j].clear();
        // 요소의 10^n번째 자리 숫자를 계산하여 해당하는 버킷에 저장
        for (int n = 0; n < N; ++n)
        {
            int d_num = (arr[n] / p10[i]) % 10;
            bucket[d_num].emplace_back(arr[n]);
        }
        // 버킷에 저장된 요소를 재배치
        int idx = 0;
        for (int j = 0; j < 10; ++j)
        {
            for (auto x : bucket[j]) arr[idx++] = x;
        }
    }
}

void solution()
{
    copy(init, init + 10, arr);
    radix_sort();
    // 출력
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    cout << "\n";
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