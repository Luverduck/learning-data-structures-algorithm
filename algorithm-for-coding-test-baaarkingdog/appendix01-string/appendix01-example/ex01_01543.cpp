#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1543
 */

string s, p;

void solution()
{
    getline(cin, s);
    getline(cin, p);
    int res = 0;
    int pos = s.find(p);
    while (pos != string::npos)
    {
        res++;
        pos = s.find(p, pos + p.size());
    }
    cout << res;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}