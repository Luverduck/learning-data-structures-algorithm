#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11723
 */

int S;

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
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove")
        {
            cin >> x;
            S &= (~(1 << (x - 1)));
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << ((S >> (x - 1)) & 1) << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (cmd == "all")
        {
            S = 0xfffff;
        }
        else if (cmd == "empty")
        {
            S = 0;
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