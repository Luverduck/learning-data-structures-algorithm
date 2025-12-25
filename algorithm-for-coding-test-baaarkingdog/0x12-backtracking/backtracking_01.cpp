#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/15649
 */

// 선택 가능한 가장 큰 자연수 N, 선택할 수 있는 자연수의 개수 M
int N, M;
// 선택된 자연수
int arr[10];
// 자연수 선택 여부
bool isused[10];

void backtracking(int k)
{
    // 1. 현재 노드 방문
    // - 현재 선택한 노드에서 조건을 만족하는지 확인한다.
    if (k == M)
    {
        // - 조건을 만족하는 경우 현재 노드의 결과를 저장하거나 출력한다.
        for (int i = 0; i < M; ++i)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    // 2. 다음 후보군 생성
    // - 현재 상태에서 방문할 수 있는 모든 자식 노드를 나열한다.
    for (int i = 0; i <= N; ++i)
    {
        // 3. 조건 확인
        // - 후보군의 각각의 자식 노드가 제약 조건을 만족하는지 검사한다.
        if (!isused[i]) // 제약 조건을 만족하는 경우
        {
            // 해당 자식 노드를 다음 방문 노드로 선택한다.
            arr[k] = i;
            isused[i] = true;
            // 해당 자식 노드로 이동하여 1번 단계를 수행한다. (재귀 호출)
            backtracking(k + 1);
            // 다음 후보군 탐색을 위해 다음 방문 노드의 선택 상태를 이전 상태로 복원한다.
            isused[i] = false;
        }
        // 제약 조건을 만족하지 않는 경우
        // 해당 노드를 버리고 다음 후보를 확인한다. (가지치기)
    }
    // 4. 이전 상태 복귀
    // - 모든 자식 노드를 탐색했거나 유망한 후보가 없는 경우 부모 노드로 돌아가서 다른 경로를 탐색한다.
}

void solution()
{
    cin >> N >> M;
    // 백트래킹 시작 (초기에 선택된 숫자는 0개)
    backtracking(0);
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