#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

void quick_sort(int start, int end)
{
    if (start + 1 >= end) return;
    int pivot = arr[start];
    int l_idx = start + 1;
    int r_idx = end - 1;
    for (int i = start; i < end; ++i)
    {
        while (arr[l_idx] < pivot) l_idx++;
        while (arr[r_idx] > pivot) r_idx--;
        if (l_idx > r_idx) break;
        swap(arr[l_idx], arr[r_idx]);
    }
    swap(arr[start], arr[r_idx]);
    quick_sort(start, r_idx);
    quick_sort(r_idx + 1, end);
}

void solution()
{
    copy(init, init + 10, arr);
    quick_sort(0, 10);
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