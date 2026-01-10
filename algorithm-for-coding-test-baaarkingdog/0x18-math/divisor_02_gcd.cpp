#include <bits/stdc++.h>

using namespace std;

// 최대 공약수 구하기 (유클리드 호제법)
int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

// 최소 공배수 구하기
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void solution()
{
    cout << gcd(20, 12);
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