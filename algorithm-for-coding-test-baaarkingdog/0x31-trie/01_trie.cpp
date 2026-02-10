#include <bits/stdc++.h>

using namespace std;

// 루트 정점의 번호
const int ROOT = 1;
// 정점 추가 시 부여할 번호
int unused = 2;
// 가능한 최대 정점의 수
const int MX = 10000 * 500 + 5;
// 각 정점이 문자열의 끝인지 여부
bool chk[MX];
// 각 정점에서 다음 정점의 번호 - nxt[현재 정점 번호][다음 문자 인덱스]
int nxt[MX][26];

// 트라이 초기화
void init()
{
    for (int i = 0; i < MX; ++i)
        fill(nxt[i], nxt[i] + 26, -1);
}

// 문자를 인덱스로 변환
int ctoi(char c)
{
    return c - 'A';
}

// 정점 추가
void insert(string& s)
{
    // 루트 정점을 시작 정점으로 초기화
    int cur = ROOT;
    // 문자열을 구성하는 각각의 문자에 대하여
    for (auto c : s)
    {
        // 해당 문자가 현재 정점의 다음 정점이 아닐 경우
        if (nxt[cur][ctoi(c)] == -1)
            // 현재 정점의 다음 정점으로 추가 (해당 정점에 번호 부여)
            nxt[cur][ctoi(c)] = unused++;
        // 다음 정점 탐색을 위한 현재 정점 번호 갱신
        cur = nxt[cur][ctoi(c)];
    }
    // 마지막 정점의 문자열 끝 여부를 true로 갱신 (트라이에 문자열 추가 완료)
    chk[cur] = true;
}

// 정점 조회
bool find(string& s)
{
    // 루트 정점을 시작 정점으로 초기화
    int cur = ROOT;
    // 문자열을 구성하는 각각의 문자에 대하여
    for (auto c : s)
    {
        // 다음 정점 번호가 -1일 경우
        if (nxt[cur][ctoi(c)] == -1)
            // 트라이에 저장된 문자열이 아님
            return false;
        // 다음 정점 탐색을 위한 현재 정점 번호 갱신
        cur = nxt[cur][ctoi(c)];
    }
    // 마지막 정점의 문자열의 끝 여부 반환
    return chk[cur];
}

// 정점 삭제
void erase(string& s)
{
    // 루트 정점을 시작 정점으로 초기화
    int cur = ROOT;
    // 문자열을 구성하는 각각의 문자에 대하여
    for (auto c : s)
    {
        // 다음 정점 번호가 -1일 경우
        if (nxt[cur][ctoi(c)] == -1)
            // 트라이에 저장된 문자열이 아님
            return;
        // 다음 정점 탐색을 위한 현재 정점 번호 갱신
        cur = nxt[cur][ctoi(c)];
    }
    // 마지막 정점의 문자열의 끝 여부를 false로 갱신 (문자열 삭제 완료)
    chk[cur] = false;
}

void test()
{

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