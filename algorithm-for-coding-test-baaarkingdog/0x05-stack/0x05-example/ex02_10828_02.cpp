#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1406
 */

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos] = x;
    pos++;
}

int pop()
{
    if (pos == 0) return -1;
    int el = dat[pos - 1];
    pos--;
    return el;
}

int top()
{
    if (pos == 0) return -1;
    return dat[pos - 1];
}

void solution()
{
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
            push(el);
        }
        else if (op == "pop")
        {
            cout << pop() << '\n';
        }
        else if (op == "size")
        {
            cout << pos << '\n';
        }
        else if (op == "empty")
        {
            cout << (pos == 0) << '\n';
        }
        else if (op == "top")
        {
            if (pos == 0)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << top() << '\n';
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