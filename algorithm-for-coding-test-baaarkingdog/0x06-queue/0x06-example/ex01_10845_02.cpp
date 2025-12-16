#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/10845
 */

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
    dat[tail++] = x;
}

int pop()
{
    if (head == tail) return -1;
    int el = dat[head];
    head++;
    return el;
}

int front()
{
    if (head == tail) return -1;
    return dat[head];
}

int back()
{
    if (head == tail) return -1;
    return dat[tail];
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
            cout << pop() << '\n';
        else if (op == "size")
            cout << (tail - head) << '\n';
        else if (op == "empty")
            cout << (tail == head) << '\n';
        else if (op == "front")
            cout << (tail != head ? dat[head] : -1) << '\n';
        else if (op == "back")
            cout << (tail != head ? dat[tail - 1] : -1 ) << '\n';
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