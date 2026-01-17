#include <bits/stdc++.h>

using namespace std;

int N = 10;
int arr[] { 2, 4, 6, 10, 10, 16, 16, 16, 30, 32 };

// target이 최초로 등장하는 위치
int lower_idx(int target, int len)
{
    int st = 0, en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] >= target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

// target보다 큰 값이 최초로 등장하는 위치
int upper_idx(int target, int len)
{
    int st = 0, en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }
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