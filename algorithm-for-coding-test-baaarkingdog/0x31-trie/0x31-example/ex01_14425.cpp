#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/14425
 */

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

int ctoi(char c)
{
    return c - 'a';
}

void insert(string& s)
{
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
    chk[cur] = true;
}

bool find(string& s)
{
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            return false;
        cur = nxt[cur][ctoi(c)];
    }
    return chk[cur];
}

void solution()
{
    for (int i = 0; i < MX; ++i)
        fill(nxt[i], nxt[i] + 26, -1);

    int N, M;
    cin >> N >> M;
    while (N--)
    {
        string s;
        cin >> s;
        insert(s);
    }
    int res = 0;
    while (M--)
    {
        string s;
        cin >> s;
        if (find(s)) res++;
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