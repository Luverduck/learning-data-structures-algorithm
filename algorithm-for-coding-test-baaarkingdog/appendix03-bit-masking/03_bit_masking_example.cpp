#include <bits/stdc++.h>

using namespace std;

/**
 * { 0, 1, 2, 3 }의 모든 부분 집합 출력
 */

// 백트래킹을 통한 구현
// 원소 선택 여부
bool is_used[4];
// 백트래킹
void backtracking(int k)
{
    // 모든 원소가 선택된 경우
    if (k == 4) {
        // 부분집합 출력
        cout << "{ ";
        for (int i = 0; i < 4; ++i)
        {
            if (is_used[i])
                cout << i << " ";
        }
        cout << "}\n";
        return;
    }
    // k를 선택하지 않는 경우
    backtracking(k + 1);
    // k를 선택하는 경우
    is_used[k] = true;
    backtracking(k + 1);
    // 다음 탐색을 위해 k의 선택 여부 복원
    is_used[k] = false;
}

// 브루트포스를 통한 구현
void brute_force()
{
    // 0000(0) ~ 1111(16)에 대하여
    // 각 자리의 값을 부분집합에 포함되었는지 여부로 대응시킴
    for (int tmp = 0; tmp < 16; ++tmp)
    {
        cout << "{ ";
        int brute = tmp;
        for (int i = 0; i < 4; ++i)
        {
            // 1(포함)일 경우 부분집합의 원소
            if (brute % 2 == 1) cout << i << " ";
            brute /= 2;
        }
        cout << "}\n";
    }
}

// 비트마스킹을 통한 구현
void bit_masking()
{
    for (int tmp = 0; tmp < 16; ++tmp)
    {
        cout << "{ ";
        for (int i = 0; i < 4; ++i)
        {
            if (tmp & (1 << i))
                cout << i << " ";
        }
        cout << "}\n";
    }
}

int main() {
    // backtracking(0);
    // brute_force();
    bit_masking();
}