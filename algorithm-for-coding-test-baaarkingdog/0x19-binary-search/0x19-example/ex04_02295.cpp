#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2295
 */

int N;
int a[1001];
vector<int> two;

void solution()
{
    // 입력
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 입력 정렬
    sort(a, a + N);

    // a[i] + a[j] 조합에 대한 배열 구성
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
            two.emplace_back(a[i] + a[j]);
    // a[i] + a[j] 조합에 대한 배열 정렬
    sort(two.begin(), two.end());

    // a[i] + a[j] == a[l] - a[k]를 만족하는 a[l] 출력
    // >> a[i] + a[j] + a[k] == a[l]는 a[i] + a[j] == a[l] - a[k]와 같다.
    for (int l = N - 1; l > 0; l--)
    {
        for (int k = 0; k < l; ++k)
        {
            if (binary_search(two.begin(), two.end(), a[l] - a[k]))
            {
                cout << a[l];
                return;
            }
        }
    }
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