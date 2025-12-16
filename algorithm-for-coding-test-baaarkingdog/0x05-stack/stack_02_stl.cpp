#include <bits/stdc++.h>

using namespace std;

int main() {
    // stack 생성 및 초기화
    stack<int> stk0;
    stack<int> stk1({ 1, 2, 3 });
    stack<int> stk2(deque<int> { 1, 2, 3 });
    stack<int> stk3(stk2);

    // >> [ E, D, C, B, A ]
    stack<string> stk({ "A", "B", "C", "D", "E" });

    // 맨 위의 요소 반환
    // >> E
    string stk_top_element = stk.top();

    // 맨 위에 요소 추가
    // >> [ F, E, D, C, B, A ]
    stk.emplace("F");

    // 맨 위의 요소 제거
    // >> [ E, D, C, B, A ]
    stk.pop();

    // 요소의 수 반환
    size_t stk_size = stk.size();

    // 비어있는지 여부 반환
    bool stk_empty = stk.empty();
}