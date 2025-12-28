#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1431
 */

bool comp(string& a, string& b)
{
    int a_len = a.size(), b_len = b.size();
    if (a_len != b_len)
        return a_len < b_len;

    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < a_len; ++i)
    {
        if (isdigit(a[i])) a_sum += (a[i] - '0');
        if (isdigit(b[i])) b_sum += (b[i] - '0');
    }
    if (a_sum != b_sum)
        return a_sum < b_sum;
    return a < b;
}

void solution()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end(), comp);
    for (string& s : v) cout << s << "\n";
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