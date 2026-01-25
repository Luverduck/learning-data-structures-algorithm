#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/1991
 */

// 왼쪽 자식 정보를 저장할 배열
int lc[27];
// 왼쪽 자식 정보를 저장할 배열
int rc[27];

// 전위 순회
void pre_order(int cur)
{
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0) pre_order(lc[cur]);
    if (rc[cur] != 0) pre_order(rc[cur]);
}

// 중위 순회
void in_order(int cur)
{
    if (lc[cur] != 0) in_order(lc[cur]);
    cout << static_cast<char>(cur + 'A' - 1);
    if (rc[cur] != 0) in_order(rc[cur]);
}

// 후위 순회
void post_order(int cur)
{
    if (lc[cur] != 0) post_order(lc[cur]);
    if (rc[cur] != 0) post_order(rc[cur]);
    cout << char(cur + 'A' - 1);
}

void solution()
{
    // 입력 및 자식 정보 배열 초기화
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char cur, left, right;
        cin >> cur >> left >> right;
        // char를 int 타입으로 변환하여 저장
        if (left != '.') lc[cur - 'A' + 1] = left - 'A' + 1;
        if (right != '.') rc[cur - 'A' + 1] = right - 'A' + 1;
    }
    pre_order(1); cout << "\n";
    in_order(1); cout << "\n";
    post_order(1);
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