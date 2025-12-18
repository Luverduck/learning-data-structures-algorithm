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
    int tmp = 1;
    deque<char> dq;
    for (int i = 0; i < input.size(); ++i)
    {

        if (input[i] == '(')
        {
            dq.emplace_front(input[i]);
            tmp *= 2;
        }
        else if (input[i] == '[')
        {
            dq.emplace_front(input[i]);
            tmp *= 3;
        }
        else if (input[i] == ')')
        {
            if (dq.empty() || dq.front() != '(')
            {
                cout << 0;
                return;
            }
            if (input[i - 1] == '(') res += tmp;
            dq.pop_front();
            tmp /= 2;
        }
        else if (input[i] == ']')
        {
            if (dq.empty() || dq.front() != '[')
            {
                cout << 0;
                return;
            }
            if (input[i - 1] == '[') res += tmp;
            dq.pop_front();
            tmp /= 3;
        }
    }
    cout << (dq.empty() ? res : 0);
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