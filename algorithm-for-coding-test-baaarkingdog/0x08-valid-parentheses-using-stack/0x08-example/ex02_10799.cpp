#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2504
 */

void solution()
{
    string input;
    cin >> input;

    int res = 0;
    deque<char> dq;
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '(') dq.emplace_front(input[i]);
        else
        {
            if (input[i - 1] == '(')
            {
                dq.pop_front();
                res += dq.size();
            }
            else if (dq.front() == '(')
            {
                dq.pop_front();
                res++;
            }
        }
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