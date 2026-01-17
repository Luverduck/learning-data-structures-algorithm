#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/7785
 */

int N;
set<string> s;

void solution()
{
    cin >> N;

    string name, log;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }

    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<>());
    for (string& x : v) cout << x << "\n";
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