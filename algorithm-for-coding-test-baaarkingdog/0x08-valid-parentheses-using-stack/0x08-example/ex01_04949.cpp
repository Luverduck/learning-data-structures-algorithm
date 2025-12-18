#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/4949
 */

void solution()
{
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == ".") break;
        bool is_valid = true;
        deque<char> dq;
        for (char& c : input)
        {
            if (c == '(' || c == '[') dq.emplace_front(c);
            else if (c == ')')
            {
                if (dq.empty() || dq.front() != '(')
                {
                    is_valid = false;
                    break;
                }
                dq.pop_front();
            }
            else if (c == ']')
            {
                if (dq.empty() || dq.front() != '[')
                {
                    is_valid = false;
                    break;
                }
                dq.pop_front();
            }
        }
        cout << (is_valid && dq.empty() ? "yes" : "no") << '\n';
    }
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