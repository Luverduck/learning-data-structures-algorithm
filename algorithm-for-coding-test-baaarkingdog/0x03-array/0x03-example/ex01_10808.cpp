#include <bits/stdc++.h>

using namespace std;

void solution()
{
    int freq['z' - 'a' + 1] { 0, };
    string input;
    cin >> input;
    for (char& c : input) freq[c - 'a']++;
    for (int& i : freq) cout << i << ' ';
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