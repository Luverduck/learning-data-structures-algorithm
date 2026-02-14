#include <bits/stdc++.h>

using namespace std;

int x = 0b01101011;

// 오른쪽에서 k번째 비트값 출력
int bit_check(int k)
{
    return x & (1 << k);
}

// 오른쪽에서 k번째 비트 켜기
void bit_on(int k)
{
    x |= (1 << k);
}

// 오른쪽에서 k번째 비트 끄기
void bit_off(int k)
{
    x &= ~(1 << k);
}

// 오른쪽에서 k번째 비트 토글
void bit_toggle(int k)
{
    x ^= (1 << k);
}

// 비트값이 1인 비트 수 반환
int bit_count()
{
    int cnt = 0;
    while (x > 0)
    {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

int main() {
    // 비트 확인
    x = 0b01101011;
    bool bit = bit_check(1);
    cout << bitset<1>(bit) << "\n";

    // 비트 On
    bit_on(2);
    cout << bitset<8>(x) << "\n";

    // 비트 Off
    bit_off(2);
    cout << bitset<8>(x) << "\n";

    // 비트 Toggle
    bit_toggle(7);
    cout << bitset<8>(x) << "\n";
    bit_toggle(7);
    cout << bitset<8>(x) << "\n";

    // 비트 On 상태인 비트 수 확인
    int cnt = bit_count();
    cout << cnt << "\n";
}