#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[] { 2, 4, 6, 13, 16, 19, 22, 23, 30, 32 };

// 이분 탐색
int binary_search(int target)
{
    // 시작 위치와 끝 위치 지정
    int st = 0, en = N - 1;
    // 시작 위치와 끝 위치가 서로 역전(st > en)될 때 종료
    while (st <= en)
    {
        // 중간 위치 계산
        int mid = (st + en) / 2;
        // 중간 위치 데이터가 대상보다 작을 경우
        if (arr[mid] < target)
            // 시작 위치를 중간 위치+1로 변경
            st = mid + 1;
        // 중간 위치 데이터가 대상보다 클 경우
        else if (arr[mid] > target)
            // 끝 위치를 중간 위치-1로 변경
            en = mid - 1;
        // 중간 위치의 데이터가 대상과 같을 경우
        else
            // 탐색 대상을 발견했으며 탐색 종료
            return 1;
    }
    // 대상을 발견하지 못했으며 탐색 종료
    return 0;
}

void solution()
{
    for (int i : { 19, 10, 25 })
        cout << binary_search(i) << "\n";
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