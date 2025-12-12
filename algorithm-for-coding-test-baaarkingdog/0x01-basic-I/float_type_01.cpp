#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 1. 실수의 저장/연산 과정에서 반드시 오차가 발생한다.
    cout << "case 1 : ";
    if (0.1 + 0.1 + 0.1 == 0.3) cout << "true";
    else cout << "false";
    cout << '\n';

    // 2. double에 long long 범위의 정수를 저장하면 안된다.
    cout << "case 2 : ";
    double x = 10000000000000001;
    double y = 10000000000000000;
    if (x == y) cout << "true";
    else cout << "false";
    cout << '\n';

    // 3. 실수를 비교할 때는 등호를 사용하면 안된다.
    cout << "case 3 : ";
    double p = 0.1 + 0.1 + 0.1;
    double q = 0.3;
    if (p == q) cout << "true";
    if (abs(p - q) < 1e-12) cout << "false";
}