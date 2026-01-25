#include <bits/stdc++.h>

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

// 전위 순회
void pre_order(int cur)
{
    cout << cur;
    if (lc[cur] != 0) pre_order(lc[cur]);
    if (rc[cur] != 0) pre_order(lc[cur]);
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    pre_order(1);
}