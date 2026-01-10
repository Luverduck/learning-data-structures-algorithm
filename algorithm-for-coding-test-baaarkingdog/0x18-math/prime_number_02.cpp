#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

// n 이하의 모든 소수 판별 (에라토스테네스의 체)
void sieve(int n)
{
    // 1부터 n까지 모든 자연수의 소수 판정 상태를 true로 초기화
    vector<bool> state(n + 1, true); // bool[]이 아닌 vector<bool>로 선언시 요소 크기를 1bit로 최적화
    // 1은 소수가 아니므로 1의 소수 판정 상태를 false로 변경
    state[1] = false;
    // 2부터 √n 사이의 자연수 i에 대하여
    for (int i = 2; i * i < n; ++i)
    {
        // i가 소수가 아닐 경우 다음 자연수 판정으로 건너뛰기
        if (!state[i]) continue;
        // i가 소수일 경우 i의 모든 배수의 소수 판정 상태를 false로 변경
        // - j = i * i부터 소수 판정 상태 변경 진행
        for (int j = i * i; j <= n; j += i)
        {
            state[j] = false;
        }
    }
    // 1부터 n까지 모든 자연수들 중 소수 판정 상태가 true인 수를 소수로 판정
    for (int i = 2; i <= n; ++i)
    {
        if (state[i]) primes.emplace_back(i);
    }
}

void solution()
{
    sieve(100);
    for (auto& i : primes) cout << i << " ";
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