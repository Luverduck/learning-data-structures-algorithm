#include <bits/stdc++.h>

using namespace std;

vector<int> divisors;

void divisor(int n)
{
    // 1 ~ √n까지 약수 판별
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0) divisors.emplace_back(i);
    }
    // √n ~ n까지 약수 판별
    for (int j = (int) divisors.size() - 1; j >= 0; --j)
    {
        if (divisors[j] * divisors[j] == n) continue;
        divisors.emplace_back(n / divisors[j]);
    }
}

void solution()
{
    divisor(10);
    for (int& i : divisors) cout << i << " ";
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