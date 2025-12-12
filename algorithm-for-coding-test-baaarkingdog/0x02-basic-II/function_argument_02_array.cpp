#include <bits/stdc++.h>

using namespace std;

void func(int arr[])
{
    arr[0] = 100;
}

int main()
{
    int arr[] { 1, 2, 3 };
    func(arr);
    cout << arr[0];
}