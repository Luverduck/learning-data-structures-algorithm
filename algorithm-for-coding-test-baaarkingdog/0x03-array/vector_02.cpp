#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 };

    // 1. for loop
    for (int i = 0; i < v.size(); ++i) cout << v[i] << '\n';

    // 2. range-based for loop (C++ 11 이후)
    for (auto& i : v) cout << i;
}