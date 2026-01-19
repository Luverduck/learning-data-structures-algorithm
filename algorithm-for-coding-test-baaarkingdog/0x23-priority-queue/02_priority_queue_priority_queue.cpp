#include <bits/stdc++.h>

using namespace std;

void test()
{
    vector<int> v { 1, 2, 2, 3, 3, 4, 5 };

    // priority_queue 생성 및 초기화 (기본 최대힙)
    priority_queue<int> pq1;
    priority_queue<int> pq2(v.begin(), v.end());
    priority_queue<int> pq3(pq2);
    // 최소힙
    priority_queue<int, vector<int>, greater<int>> pq4(v.begin(), v.end());


    priority_queue<int> pq(v.begin(), v.end());

    // 요소 삽입
    pq.push(10);

    // 우선순위가 가장 높은 요소 제거
    pq.pop();

    // 우선순위가 가장 높은 요소 반환
    int pq_top_element = pq.top();

    // 요소의 수 반환
    int pq_size = pq.size();

    // 비어있는지 여부 반환
    bool pq_empty = pq.empty();
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