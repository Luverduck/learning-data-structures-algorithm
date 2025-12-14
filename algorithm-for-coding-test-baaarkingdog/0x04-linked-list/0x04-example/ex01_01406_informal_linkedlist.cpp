#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1406
 */

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char val)
{
    dat[unused] = val;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

void solution()
{
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string input;
    cin >> input;
    int cursor = 0;
    for (char& c : input)
    {
        insert(cursor, c);
        cursor++;
    }

    int M;
    cin >> M;
    while (M--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            if (pre[cursor] != -1) cursor = pre[cursor];
        }
        else if (op == 'D')
        {
            if (nxt[cursor] != -1) cursor = nxt[cursor];
        }
        else if (op == 'B')
        {
            if (cursor != 0)
            {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
        else if (op == 'P')
        {
            char c;
            cin >> c;
            insert(cursor, c);
            cursor = nxt[cursor];
        }
    }
    traverse();
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