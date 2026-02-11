#include <bits/stdc++.h>

using namespace std;

// 구분자를 기준으로 문자열 나누기
vector<string> split(string& s, string& sep)
{
    // 토큰 문자열을 저장하기 위한 벡터
    vector<string> ret;
    // 현재 위치
    int pos = 0;
    // 문자열의 끝에 도달할 때까지 반복
    while (pos < s.size())
    {
        // 문자열의 현재 위치부터 시작하여 패턴 문자열 탐색
        int nxt_pos = s.find(sep, pos);
        // 문자열이 패턴 문자열을 포함하지 않을 경우 탐색 종료
        if (nxt_pos == -1) nxt_pos = s.size();
        // 문자열이 패턴 문자열을 포함하는 경우
        if (nxt_pos - pos > 0)
            // 현재 위치부터 패턴 문자열 위치의 이전 위치까지의 문자열 추출 후 벡터에 저장
            ret.emplace_back(s.substr(pos, nxt_pos - pos));
        // 현재 위치를 패턴 문자열 위치의 다음 위치로 갱신
        pos = nxt_pos + sep.size();
    }
    // 벡터 반환
    return ret;
}

void test()
{
    string s = "ABC DEF";
    string separator = " ";
    vector<string> ret = split(s, separator);
    for (auto& s : ret) cout << s << " ";
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