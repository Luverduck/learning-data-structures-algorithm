#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/15688
 */

int N;
int freq[20000001];

void solution()
{
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;
        freq[num + 1000000]++;
    }

    for (int i = 0; i < 2000001; ++i)
    {
        if (freq[i] == 0) continue;
        while (freq[i]--)
            cout << (i - 1000000) << '\n';
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