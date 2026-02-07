#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/16916
 */

// 실패 함수 구성
vector<int> failure(string& s)
{
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        // s[i]과 s[j]가 서로 다를 경우
        while (j > 0 && s[i] != s[j])
            j = f[j - 1]; // 이전 일치 지점으로 이동
        // s[i]과 s[j]가 서로 같을 경우
        if (s[i] == s[j])
            f[i] = ++j; // 공통 부분의 최대 길이 증가
    }
    return f;
}

// KMP 알고리즘
void kmp(string& s, string& p)
{
    // 실패 함수 구성
    vector<int> f = failure(p);
    // 패턴 문자열 P의 인덱스 j
    int j = 0;
    // 문자열 S에서 패턴 문자열 P 포함 여부 탐색
    for (int i = 0; i < s.size(); ++i)
    {
        // S[i]와 P[j]가 일치하지 않을 경우 j를 F(j-1)로 갱신
        while (j > 0 && s[i] != p[j]) j = f[j - 1];
        // S[i]와 P[j]가 일치할 경우 j 증가
        if (s[i] == p[j]) ++j;
        // j가 패턴 문자열 P의 길이와 같을 경우 탐색 성공
        if (j == p.size())
        {
            cout << 1;
            return;
        }
    }
    // 그 외 탐색 실패
    cout << 0;
}

void solution()
{
    string S, P;
    cin >> S >> P;
    kmp(S, P);
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