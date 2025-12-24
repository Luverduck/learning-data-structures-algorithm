#include <bits/stdc++.h>

using namespace std;

// 재귀를 통해 N부터 1까지 출력하는 함수
void func1(int N) {
    if (N <= 0) return;
    cout << N << ' ';
    func1(N - 1);
}

// 재귀를 통해 1부터 N까지 출력하는 함수
void func2(int N) {
    if (N > 1) func2(N - 1);
    cout << N << ' ';
}

void solution() {
    func1(10); cout << '\n';
    func2(10);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}