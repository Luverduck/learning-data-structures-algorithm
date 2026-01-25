#include <bits/stdc++.h>

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

// 레벨 순회
void level_order()
{
    queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        if (lc[cur]) que.push(lc[cur]);
        if (rc[cur]) que.push(rc[cur]);
    }
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    level_order();
}