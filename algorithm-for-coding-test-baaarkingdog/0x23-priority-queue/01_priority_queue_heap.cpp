#include <bits/stdc++.h>

using namespace std;

// 힙
int heap[100005];
// 힙의 크기
int sz = 0;

// 요소 삽입
void push(int x)
{
    // 맨 끝에 요소 삽입
    heap[++sz] = x;
    // 삽입한 요소보다 값이 작은 부모 노드를 만날 때까지 반복
    int idx = sz; // 삽입한 요소의 인덱스
    while (idx != 1)
    {
        // 삽입한 요소에 대하여 부모 노드의 인덱스
        int parent = idx / 2;
        // 삽입한 요소보다 부모 노드의 값이 작을 경우 자리 바꾸기
        if (heap[idx] >= heap[parent]) break;
        swap(heap[idx], heap[parent]);
        idx = parent;
    }
}

// 우선순위가 가장 높은 요소
int top()
{
    if (sz == 0) return -1;
    return heap[1];
}

// 우선순위가 가장 높은 요소 삭제
void pop()
{
    if (sz == 0) return;
    // 맨 끝의 요소를 루트 노드로 이동
    heap[1] = heap[sz--];
    // 이동한 요소보다 큰 자식 노드를 만날 때까지 반복
    int idx = 1; // 이동한 요소의 인덱스
    while (2 * idx < sz)
    {
        // 왼쪽 자식 노드와 오른쪽 자식 노드의 인덱스
        int lc = 2 * idx;
        int rc = 2 * idx + 1;
        // 자식 노드 중 최소값인 자식 노드의 인덱스
        int min_child = lc;
        if (rc <= sz && heap[lc] > heap[rc]) min_child = rc;
        // 이동한 요소가 최소값인 자식 노드보다 값이 클 경우 자리 바꾸기
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

void test()
{
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
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