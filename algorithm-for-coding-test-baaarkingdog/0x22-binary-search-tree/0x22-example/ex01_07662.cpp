#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/7662
 */

int T, K;

void solution()
{
    cin >> T;
    while (T--)
    {
        cin >> K;
        multiset<int> Q;
        for (int i = 0; i < K; ++i)
        {
            char op;
            cin >> op;
            if (op == 'I')
            {
                int val;
                cin >> val;
                Q.emplace(val);
            }
            else
            {
                int flag;
                cin >> flag;
                if (Q.empty()) continue;
                if (flag == 1) Q.erase(prev(Q.end()));
                else Q.erase(Q.begin());
            }
        }
        if (Q.empty()) cout << "EMPTY";
        else cout << *prev(Q.end()) << " " << *Q.begin();
        cout << '\n';
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