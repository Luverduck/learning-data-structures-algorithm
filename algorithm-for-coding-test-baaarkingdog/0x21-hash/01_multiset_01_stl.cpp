#include <bits/stdc++.h>

using namespace std;

void test()
{
    vector<int> v { 1, 2, 2, 3, 3, 4, 5 };

    // unordered_multiset 생성 및 초기화 (기본 오름차순 정렬)
    unordered_multiset<int> ms0;
    unordered_multiset<int> ms1 { 1, 2, 2, 3, 3, 4, 5 };
    unordered_multiset<int> ms2(v.begin(), v.end());
    unordered_multiset<int> ms3(ms2);

    // >> [ A, B, C, C, E, F ]
    unordered_multiset<string> ms { "A", "C", "C", "B", "E", "F" };

    // 첫 번째 요소의 위치를 가리키는 정방향 반복자 반환
    unordered_multiset<string>::iterator ms_begin_iter = ms.begin();
    // 마지막 요소의 다음 위치를 정방향 반복자 반환
    unordered_multiset<string>::iterator ms_end_iter = ms.end();

    // 요소 삽입 후 삽입 위치와 성공 여부의 pair 반환
    // >> [ A, B, C, C, D, E, F ]
    unordered_multiset<string>::iterator ms_insert_iter1 = ms.insert("D");

    // 특정 위치를 기준으로 탐색하여 요소 삽입
    // >> [ A, B, C, C, D, E, E, F ]
    unordered_multiset<string>::iterator ms_insert_iter2 = ms.insert(ms.end(), "E");

    // 요소 제거 후 제거한 요소의 수 반환
    // >> [ A, B, C, C, D, F ]
    size_t ms_erase1 = ms.erase("E");

    // 요소 제거 후 제거한 요소의 다음 위치를 가리키는 반복자 반환
    // >> [ A, B, C, C, D ]
    unordered_multiset<string>::iterator ms_erase_iter = ms.erase(ms.find("F"));

    // 특정 요소의 수 반환
    // >> 2
    size_t ms_count = ms.count("C");

    // 특정 요소의 위치를 가리키는 반복자 반환
    unordered_multiset<string>::iterator ms_find_iter = ms.find("C");

    // 요소의 수 반환
    size_t ms_size = ms.size();

    // 모든 요소 비우기
    // >> []
    ms.clear();

    // 비어있는지 여부 반환
    bool ms_empty = ms.empty();
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