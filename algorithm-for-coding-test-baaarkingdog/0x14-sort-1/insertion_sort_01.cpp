#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

void insertion_sort()
{
    for (int i = 1; i < N; ++i)
    {
        int ins_data = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > ins_data)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ins_data;
    }
}

void solution()
{
    copy(init, init + 10, arr);
    insertion_sort();
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