#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1715
 */

void solution()
{
    // 입력
    int N;
    cin >> N;
    // 입력 데이터로 최소 힙 우선순위 큐 구성
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i)
    {
        int X;
        cin >> X;
        pq.push(X);
    }
    // 카드 수가 최소인 카드 묶음부터 합치기
    int res = 0;
    // 카드 묶음이 하나가 될 때까지 반복
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        // 매 번 합치기에 필요한 비교 횟수 가산
        res += a + b;
        // 다음 합치기를 위해 우선순위 큐에 다시 저장
        pq.push(a + b);
    }
    cout << res;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("fileio/input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}