#include <bits/stdc++.h>

using namespace std;

void test()
{
    vector<int> v { 1, 2, 2, 3, 3, 4, 5 };

    // set 생성 및 초기화 (기본 오름차순 정렬)
    unordered_set<int> s0;
    unordered_set<int> s1 { 1, 2, 2, 3, 3, 4, 5 };
    unordered_set<int> s2(v.begin(), v.end());
    unordered_set<int> s3(s2);

    // >> [ A, C, B, E, F ]
    unordered_set<string> s { "A", "C", "C", "B", "E", "F" };

    // 첫 번째 요소의 위치를 가리키는 정방향 반복자 반환
    unordered_set<string>::iterator s_begin_iter = s.begin();
    // 마지막 요소의 다음 위치를 정방향 반복자 반환
    unordered_set<string>::iterator s_end_iter = s.end();

    // 요소 삽입 후 삽입 위치와 성공 여부의 pair 반환
    // >> [ A, C, B, E, F, D ]
    pair<unordered_set<string>::iterator, bool> s_insert_pair = s.insert("D");

    // 특정 위치를 기준으로 탐색하여 요소 삽입
    // >> [ A, C, B, E, F, D, G ]
    unordered_set<string>::iterator s_insert_iter = s.insert(s.end(), "G");

    // 요소 제거 후 제거한 요소의 수 반환
    // >> [ A, C, B, E, D, G ]
    size_t s_erase = s.erase("F");

    // 요소 제거 후 제거한 요소의 다음 위치를 가리키는 반복자 반환
    // >> [ A, B, C, D, E ]
    unordered_set<string>::iterator s_erase_iter = s.erase(s.find("G"));

    // 특정 요소의 수 반환
    // >> 1
    size_t s_count = s.count("A");

    // 특정 요소의 위치를 가리키는 반복자 반환
    unordered_set<string>::iterator s_find_iter = s.find("B");

    // 요소의 수 반환
    size_t s_size = s.size();

    // 모든 요소 비우기
    // >> []
    s.clear();

    // 비어있는지 여부 반환
    bool s_empty = s.empty();
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