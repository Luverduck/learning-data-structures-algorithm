#include <bits/stdc++.h>

using namespace std;

void solution()
{
    int int_min = numeric_limits<int>::min();
    cout << (int_min - 2) << '\n';

    int int_max = numeric_limits<int>::max();
    cout << (int_max + 2) << '\n';
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}