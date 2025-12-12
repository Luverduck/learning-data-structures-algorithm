#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif

    // C 입출력 스트림과의 동기화 해제
    ios::sync_with_stdio(0);
    // cin 수행 전 cout 버퍼 비우기 설정 해제
    cin.tie(0);

    string s;
    getline(cin, s);
    cout << s;
}