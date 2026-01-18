#include <bits/stdc++.h>

using namespace std;

void test()
{
    vector<pair<string, int>> v { {"A", 1}, {"C", 2}, {"C", 3}, {"B", 4}, {"E", 5}, {"D", 6} };

    // map 생성 및 초기화
    map<string, int> m0;
    map<string, int> m1 { {"A", 1}, {"C", 2}, {"C", 3}, {"B", 4}, {"E", 5}, {"D", 6} };
    map<string, int> m2(v.begin(), v.end());
    map<string, int> m3(m2);
    // Key를 기준으로 내림차순 정렬
    map<string, int, greater<string>> m4(v.begin(), v.end());

    map<string, int> m { {"A", 1}, {"C", 2}, {"C", 3}, {"B", 4}, {"E", 5}, {"D", 6} };

    // 첫 번째 요소의 위치를 가리키는 정방향 반복자 반환
    map<string, int>::iterator m_begin_iter = m.begin();
    // 마지막 요소의 다음 위치를 정방향 반복자 반환
    map<string, int>::iterator m_end_iter = m.end();

    // 마지막 요소의 위치를 가리키는 역방향 반복자 반환
    map<string, int>::reverse_iterator m_rbegin_riter = m.rbegin();
    // 첫 번째 요소의 이전 위치를 가리키는 역방향 반복자 반환
    map<string, int>::reverse_iterator m_rend_riter = m.rend();

    // 특정 key를 가진 요소의 시작 위치와 끝 위치를 가리키는 반복자의 pair 반환
    pair<map<string, int>::iterator, map<string, int>::iterator> m_equal_range_pair = m.equal_range("C");

    // 특정 key를 가진 요소의 value 접근
    int m_key_value = m["C"];
    int m_at_value = m.at("C");

    // 요소 삽입 (pair 생성 후 삽입 시도, 삽입 실패 시 pair 파괴)
    pair<map<string, int>::iterator, bool> m_emplace_pair = m.emplace("F", 7);
    // 요소 삽입 (삽입 전 key 중복 검사, key 중복 시 pair 생성 안함)
    pair<map<string, int>::iterator, bool> m_try_emplace_pair = m.try_emplace("G", 8);
    // 요소 삽입
    pair<map<string, int>::iterator, bool> m_insert_pair = m.insert({"H", 9});

    // 특정 key를 가진 요소 삭제
    size_t m_erase = m.erase("H");

    // 특정 위치의 요소 삭제
    map<string, int>::iterator m_erase_iter1 = m.erase(m.find("G"));

    // 특정 범위의 요소 삭제
    map<string, int>::iterator m_erase_iter2 = m.erase(m.find("E"), m.find("F"));

    // 특정 key를 가진 요소의 수 반환
    size_t m_count = m.count("B");

    // 특정 key를 가진 요소의 위치를 가리키는 반복자 반환
    map<string, int>::iterator m_find_iter = m.find("B");

    // 특정 key 값보다 크거나 같은 첫 번째 요소의 위치를 가리키는 반복자 반환
    map<string, int>::iterator m_lower_bound_iter = m.lower_bound("B");

    // 특정 key 값보다 큰 첫 번째 요소의 위치를 가리키는 반복자 반환
    map<string, int>::iterator m_upper_bound_iter = m.upper_bound("B");

    // 요소의 수 반환
    size_t m_size = m.size();

    // 모든 요소 비우기
    m.clear();

    // 비어있는지 여부 반환
    bool m_emtpy = m.empty();
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