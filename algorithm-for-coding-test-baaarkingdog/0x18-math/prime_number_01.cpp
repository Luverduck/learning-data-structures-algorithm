#include <bits/stdc++.h>

using namespace std;

// n이 소수인지 판정
bool is_prime(int n)
{
    // 1은 소수가 아님
    if (n == 1) return false;
    // 2부터 √n 사이의 자연수 i에 대하여
    // n을 i로 나누었을 때 나누어 떨어지는 수가 있을 경우 소수가 아님
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    // 위 두 가지 경우를 모두 만족하지 않는 자연수를 소수로 판정
    return true;
}

void solution()
{
    for (int i = 1; i <= 100; ++i)
    {
        if (!is_prime(i)) continue;
        cout << i << " ";
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