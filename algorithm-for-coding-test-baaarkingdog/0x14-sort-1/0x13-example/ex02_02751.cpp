#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2751
 */

int N;
int arr[1000001];
int tmp[1000001];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int l = start;
    int r = mid;
    for (int i = start; i < end; ++i)
    {
        if (l == mid) tmp[i] = arr[r++];
        else if (r == end) tmp[i] = arr[l++];
        else if (arr[l] > arr[r]) tmp[i] = arr[r++];
        else tmp[i] = arr[l++];
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
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    merge_sort(0, N);
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
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