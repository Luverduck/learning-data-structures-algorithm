#include <bits/stdc++.h>

using namespace std;

void func(int a)
{
    a = 5;
}

int main()
{
    int x = 0;
    func(x);
    cout << x;
}