#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 배열의 모든 요소를 특정 값으로 초기화
    int arr1d[21];
    int arr2d[21][21];

    // 1. <cstring>의 memset() (비추천)
    memset(arr1d, 0, sizeof arr1d);
    memset(arr2d, 0, sizeof arr2d);

    // 2. for문
    for (int i = 0; i < 21; ++i) arr1d[i] = 10;
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 21; ++j)
        {
            arr2d[i][j] = 10;
        }
    }

    // 3. <algorithm>의 fill() (추천)
    fill(arr1d, arr1d + 21, 10);
    for (int i = 0; i < 21; ++i)
        fill(arr2d[i], arr2d[i] + 21, 20);
}