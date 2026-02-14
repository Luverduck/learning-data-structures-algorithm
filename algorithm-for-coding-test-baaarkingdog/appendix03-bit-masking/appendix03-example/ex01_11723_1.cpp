#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11723
 */

int S[21];

void solution()
{
    int M;
    cin >> M;
    while (M--)
    {
        string cmd;
        int x;
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> x;
            if (S[x] == 1) continue;
            S[x] = 1;
        }
        else if (cmd == "remove")
        {
            cin >> x;
            if (S[x] == 0) continue;
            S[x] = 0;
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << (S[x] == 1 ? 1 : 0) << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            S[x] = !S[x];
        }
        else if (cmd == "all")
        {
            fill(S, S + 21, 1);
        }
        else if (cmd == "empty")
        {
            fill(S, S + 21, 0);
        }
    }
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