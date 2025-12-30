#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2579
 */

int N;
int s[301];
int d[301];

void dp()
{
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for (int i = 4; i <= N - 1; ++i)
        d[i] = s[i] + min(d[i - 2], d[i - 3]);
}

void solution()
{
    cin >> N;
    int s_sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s[i];
        s_sum += s[i];
    }
    if (N <= 2)
    {
        cout << s_sum;
        return;
    }
    dp();
    cout << (s_sum - min(d[N - 2], d[N - 1]));
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