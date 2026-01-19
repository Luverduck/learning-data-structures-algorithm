#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/11286
 */

class Comp
{
public:
    bool operator() (int a, int b)
    {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

void solution()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, Comp> pq;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (x != 0)
        {
            pq.push(x);
        }
        else
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
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