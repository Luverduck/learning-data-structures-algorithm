#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2941
 */

vector<string> alphabets { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string s;

void solution()
{
    cin >> s;
    for (string& p : alphabets)
    {
        while (true)
        {
            int pos = s.find(p);
            if (pos == string::npos) break;
            s.replace(pos, p.size(), "*");
        }
    }
    cout << s.size();
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