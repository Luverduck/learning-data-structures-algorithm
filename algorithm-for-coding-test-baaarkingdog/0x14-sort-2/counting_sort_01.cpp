#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

void counting_sort()
{
    // 정렬되지 않은 요소들 중 가장 큰 요소
    int max_val = *max_element(arr, arr + N);
    // 요소 정렬을 위한 임시 배열
    int tmp[max_val];
    // 요소 등장 횟수 카운트를 위한 벡터
    vector<int> count(max_val + 1);

    // 등장 횟수 카운트
    for (int i = 0; i < N; ++i) count[arr[i]]++;

    // 등장 횟수의 누적 합 계산
    for (int i = 1; i <= max_val; ++i) count[i] += count[i - 1];

    // 요소들을 임시 배열에 재배치
    // - arr의 i번째 요소 값 num은 count의 인덱스
    // - count의 num번째 요소는 arr에서 num이 등장한 가장 마지막 위치 (위치 - 1 == 인덱스)
    for (int i = N - 1; i >= 0; --i)
    {
        tmp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 원본 배열에 복사
    copy(tmp, tmp + N, arr);
}

void solution()
{
    copy(init, init + 10, arr);
    counting_sort();
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