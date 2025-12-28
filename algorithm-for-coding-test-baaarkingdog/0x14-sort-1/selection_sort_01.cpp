#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[1000001];
int init[10] { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };

// 선택 정렬
void selection_sort()
{
    for (int i = 0; i < N; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < N; ++j)
        {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

// 선택 정렬 (STL의 min_element(), max_element() 활용)
void selection_sort_stl()
{
    for (int i = 0; i < N; ++i)
    {
        auto min_it = min_element(arr + i, arr + N);
        swap(*min_it, arr[i]);
    }
    // 출력
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    cout << "\n";
}

void solution()
{
    copy(init, init + 10, arr);
    selection_sort();
    // 출력
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    cout << "\n";
    copy(init, init + 10, arr);
    selection_sort_stl();
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