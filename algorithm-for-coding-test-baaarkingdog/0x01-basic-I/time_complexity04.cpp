#include <bits/stdc++.h>

using namespace std;

/*
 *  문제 4.
 *  N 이하의 수 중에서 가장 큰 2의 거듭제곱 수를 반환하는 함수 func4(int N)을 작성하라.
 *  N은 10억 이하의 자연수이다.
 */
int func4(int N)
{
    int res = 1;
    while (2 * res <= N) res *= 2;
    return res;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}