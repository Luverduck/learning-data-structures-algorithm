#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> l = { 1, 2 }; // 1 2

    list<int>::iterator it = l.begin();
    l.push_front(10); // 10 1 2
    cout << *it << '\n'; // 1

    l.push_back(5); // 10 1 2 5
    l.insert(it, 6); // it가 가리키는 위치에 6 삽입, 10 6 1 2 5
    it++; // it를 1칸 앞으로 전진, 현재 it가 가리키는 값은 2
    it = l.erase(it); // it가 가리키는 값 제거, 그 다음 요소인 5의 위치 반환
    cout << *it << '\n';

    for (auto& i : l) cout << i << ' ';
    cout << '\n';

    for (list<int>::iterator it = l.begin(); it != l.end(); it++) cout << *it << ' ';
}