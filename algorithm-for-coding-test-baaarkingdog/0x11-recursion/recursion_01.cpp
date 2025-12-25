#include <bits/stdc++.h>

using namespace std;

// 재귀를 통해 N부터 1까지 출력하는 함수
void recursion1(int N) {
    if (N <= 0) return;
    cout << N << ' ';
    recursion1(N - 1);
}

// 재귀를 통해 1부터 N까지 출력하는 함수
void recursion2(int N) {
    if (N > 1) recursion2(N - 1);
    cout << N << ' ';
}

void solution() {
    recursion1(10); cout << '\n';
    recursion2(10);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}