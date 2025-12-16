#include <bits/stdc++.h>

using namespace std;

int main()
{
    // deque 생성 및 초기화
    deque<int> dq0;
    deque<int> dq1(5);
    deque<int> dq2 { 1, 2, 3, 4, 5 };
    deque<int> dq3(5, 100);
    deque<int> dq4(dq2);
    deque<int> dq5(dq3.begin() + 1, dq3.begin() + 4);

    // >> [ A, B, C, D, E ]
    deque<string> dq { "A", "B", "C", "D", "E" };

    // 맨 앞 요소 접근
    string dq_front_element = dq.front();
    // 맨 뒤 요소 접근
    string dq_back_element = dq.back();

    // 맨 앞에 요소 추가
    // >> [P, A, B, C, D, E]
    dq.emplace_front("P");

    // 맨 뒤에 요소 추가
    // >> [P, A, B, C, D, E, Q]
    dq.emplace_back("Q");

    // 맨 앞의 요소 제거
    // >> [A, B, C, D, E, Q]
    dq.pop_front();

    // 맨 뒤의 요소 제거
    // >> [A, B, C, D, E]
    dq.pop_back();

    // 요소의 수 반환
    size_t dq_size = dq.size();

    // 모든 요소 비우기
    // >> []
    dq.clear();

    // 비어있는지 여부 반환
    bool dq_empty = dq.empty();
}