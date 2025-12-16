#include <bits/stdc++.h>

using namespace std;

int main() {
    // queue 생성 및 초기화
    queue<int> que0;
    queue<int> que1({ 1, 2, 3 });
    queue<int> que2(deque<int> { 1, 2, 3 });
    queue<int> que3(que2);

    // >> [ A, B, C, D, E ]
    queue<string> que({ "A", "B", "C", "D", "E" });

    // 맨 앞의 요소 반환
    // >> A
    string que_front_element = que.front();

    // 맨 뒤의 요소 반환
    // >> E
    string que_back_element = que.back();

    // 맨 뒤에 요소 추가
    // >> [ A, B, C, D, E, F ]
    que.emplace("F");

    // 맨 앞의 요소 제거
    // >> [ B, C, D, E, F ]
    que.pop();

    // 요소의 수 반환
    size_t que_size = que.size();

    // 비어있는지 여부 반환
    bool que_empty = que.empty();
}