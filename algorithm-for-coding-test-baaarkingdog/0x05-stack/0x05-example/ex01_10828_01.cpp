#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1406
 */

void solution()
{
    deque<int> dq;
    int N;
    cin >> N;
    while (N--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int el;
            cin >> el;
            dq.emplace_front(el);
        }
        else if (op == "pop")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else if (op == "size")
            cout << dq.size() << '\n';
        else if (op == "empty")
            cout << dq.empty() << '\n';
        else if (op == "top")
            cout << dq.front() << '\n';
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