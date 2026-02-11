#include <bits/stdc++.h>

using namespace std;

clock_t st, en;

// 대입 연산자(=)를 통한 문자열 추가 : O(N^2)
void simple_assignment()
{
    st = clock();
    string s;
    for (int i = 0; i < 100000; ++i)
        s = s + 'a'; // 임시 객체(s + 'a') 생성 후 s에 할당
    en = clock();
    cout << en - st << "[ms]\n";
}

// 복합 대입 연산자(+=)를 통한 문자열 추가 : O(N)
void compound_assignment()
{
    st = clock();
    string s;
    for (int i = 0; i < 100000; ++i)
        s += 'a'; // s의 끝에 'a' 추가
    en = clock();
    cout << en - st << "[ms]\n";
}

void test()
{
    simple_assignment();
    compound_assignment();
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    test();
}