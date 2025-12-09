#include <bits/stdc++.h>

using namespace std;

void solution()
{
    // char : -128 ~ 127
    char char_min = numeric_limits<char>::min();
    char char_max = numeric_limits<char>::max();
    cout << "char : " << static_cast<int>(char_min) << " ~ " << static_cast<int>(char_max) << '\n';

    // short : -32768 ~ 32767
    short short_min = numeric_limits<short>::min();
    short short_max = numeric_limits<short>::max();
    cout << "short : " << short_min << " ~ " << short_max << '\n';

    // int : -2147483648 ~ 2147483647
    int int_min = numeric_limits<int>::min();
    int int_max = numeric_limits<int>::max();
    cout << "int : " << int_min << " ~ " << int_max << '\n';

    // long long : -9223372036854775808 ~ 9223372036854775807
    long long longlong_min = numeric_limits<long long>::min();
    long long longlong_max = numeric_limits<long long>::max();
    cout << "long long : " << longlong_min << " ~ " << longlong_max << '\n';
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}