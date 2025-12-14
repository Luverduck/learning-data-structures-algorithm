#include <bits/stdc++.h>

using namespace std;

/*
 *  문제 2.
 *  주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 요소가 존재하면 1을,
 *  그렇지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
 *  arr의 각 수는 0 이상, 100 이하이고 N은 1000 이하이다.
 */
int func2(int arr[], int N)
{
    int occur[101] { 0, };
    for (int i = 0; i < N; ++i)
    {
        if (occur[100 - arr[i]] == 1) return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << func2(new int[]{ 49, 51, 2 }, 3);
}