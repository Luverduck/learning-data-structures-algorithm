#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

// 버블 정렬
void bubble_sort()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void solution()
{
    copy(init, init + 10, arr);
    bubble_sort();
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