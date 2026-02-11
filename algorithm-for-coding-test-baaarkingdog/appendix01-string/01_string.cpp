#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "Hello";
    // 문자열에서 특정 인덱스의 단일 문자 접근
    cout << s[1] << "\n"; // e
    // 문자열 끝에 또 다른 문자열 추가
    s += " BKD!";
    // 문자열의 길이 - size()
    cout << s.size() << "\n"; // 10
    // 문자열에서 부분 문자열 추출 - substr(시작 인덱스, 길이)
    cout << s.substr(2, 3) << "\n"; // llo
    // 문자열에서 특정 패턴 문자열을 또 다른 패턴 문자열로 치환
    s.replace(6, 4, "guys");
    cout << s << "\n";
    // 문자열에서 특정 패턴 문자열의 위치 조회
    int it = s.find("guys");
    s.replace(it, 4, "everyone");
    cout << s << "\n";
    // 문자열에서 특정 부분 제거 - erase(시작 인덱스, 길이)
    s.erase(7, 6);
    cout << s << "\n";
    // 문자열에서 특정 인덱스의 단일 문자 변경
    s[6] = 'm';
    cout << s << "\n";
    // 문자열에서 또 다른 문자열 삽입 - insert(시작 인덱스, 삽입 문자열)
    s.insert(0, "say");
    cout << s << "\n";
    // 문자열에서 특정 패턴 문자열을 발견하지 못할 경우 string::npos 반환
    if (s.find("to") == string::npos)
        cout << "'to' is not in string 's'\n";
}