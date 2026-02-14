#include <bits/stdc++.h>

using namespace std;

int main() {
    char A = 0b00110101; // 53 (00110101)
    char B = 0b00011001; // 25 (00011001)
    // 비트 논리 연산자
    cout << "A & B = " << (A & B) << "\t (" << bitset<8>(A & B) << ")\n";
    cout << "A | B = " << (A | B) << "\t (" << bitset<8>(A | B) << ")\n";
    cout << "A ^ B = " << (A ^ B) << "\t (" << bitset<8>(A ^ B) << ")\n";
    cout << "~A = " << (~A) << "\t (" << bitset<8>(~A) << ")\n";
    // 비트 이동 연산자
    cout << "A << 2 = " << (A << 2) << "\t (" << bitset<8>(A << 2) << ")\n";
    cout << "A >> 2 = " << (A >> 2) << "\t (" << bitset<8>(A >> 2) << ")\n";
}