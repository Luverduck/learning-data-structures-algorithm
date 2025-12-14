#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1406
 */

void solution()
{
    string input;
    int M;
    cin >> input >> M;

    list<char> l;
    for (char& c : input) l.push_back(c);
    list<char>::iterator cursor = l.end();
    while (M--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            if (cursor != l.begin()) --cursor;
        }
        else if (op == 'D')
        {
            if (cursor != l.end()) ++cursor;
        }
        else if (op == 'B')
        {
            if (cursor != l.begin()) cursor = l.erase(--cursor);
        }
        else if (op == 'P')
        {
            char c;
            cin >> c;
            l.insert(cursor, c);
        }
    }
    for (char& c : l) cout << c;
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