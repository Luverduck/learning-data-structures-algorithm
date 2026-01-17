#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1620
 */

int N, M;
unordered_map<string, int> c_stoi;
string c_itos[100001];

void solution()
{
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        string name;
        cin >> name;
        c_stoi.emplace(name, i);
        c_itos[i] = name;
    }

    for (int i = 1; i <= M; ++i)
    {
        string input;
        cin >> input;
        if (isdigit(input[0]))
            cout << c_itos[stoi(input)];
        else
            cout << c_stoi[input];
        cout << "\n";
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