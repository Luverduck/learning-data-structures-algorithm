#include <bits/stdc++.h>

using namespace std;

void func(vector<int>& v)
{
    v[10] = 100;
}

int main()
{
    vector<int> v(100);
    func(v);
    cout << v[10];
}