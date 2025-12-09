#include <bits/stdc++.h>

using namespace std;

/*
 *  문제 1.
 *  N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을
 *  반환하는 함수 funct1(int N)을 작성하라.
 */
int func1(int N)
{
    int res = 0;
    for (int i = 1; i <= N; ++i)
        if (i % 3 == 0 || i % 5 == 0) res += i;
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