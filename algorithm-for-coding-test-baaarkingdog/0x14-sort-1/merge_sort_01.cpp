#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int tmp[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int l_idx = start;
    int r_idx = mid;
    for (int i = start; i < end; ++i)
    {
        if (l_idx == mid) tmp[i] = arr[r_idx++];
        else if (r_idx == end) tmp[i] = arr[l_idx++];
        else if (arr[l_idx] > arr[r_idx]) tmp[i] = arr[r_idx++];
        else tmp[i] = arr[l_idx++];
    }
    for (int i = start; i < end; ++i) arr[i] = tmp[i];
}

void merge_sort(int start, int end)
{
    if (start + 1 == end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

void solution()
{
    copy(init, init + 10, arr);
    merge_sort(0, N);
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