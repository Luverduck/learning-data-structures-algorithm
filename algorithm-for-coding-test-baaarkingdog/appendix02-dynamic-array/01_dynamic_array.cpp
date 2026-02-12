#include <bits/stdc++.h>

using namespace std;

// 동적 배열
int* arr;
// 길이 (현재 동적 배열에 저장된 요소의 수)
int len = 0;
// 용량 (현재 동적 배열에 저장할 수 있는 최대 요소의 수)
int capacity = 0;

// 초기화
void init()
{
    arr = new int[1];
    capacity = 1;
}

// 동적 배열 확장
void expand()
{
    // 현재 용량의 2배 용량을 가지는 임시 배열 생성
    int* tmp = new int[2 * capacity];
    // 동적 배열에 저장된 값을 임시 배열로 복사
    for (int i = 0; i < len; ++i)
        tmp[i] = arr[i];
    // 동적 배열 메모리 해제
    delete[] arr;
    // 동적 배열 포인터에 임시 배열의 주소 할당
    arr = tmp;
    // 현재 용량을 이전 용량의 2배로 설정
    capacity *= 2;
}

// 동적 배열에 요소 삽입
void insert(int idx, int num)
{
    // 길이가 용량과 같을 경우
    if (len == capacity)
    {
        // 동적 배열 확장
        expand();
    }
    // 요소 삽입을 위해 기존 요소들을 뒤로 한 칸씩 이동
    for (int i = len; i > idx; --i)
        arr[i] = arr[i - 1];
    // 요소 삽입
    arr[idx] = num;
    // 길이 증가
    len++;
}

void print_arr()
{
    for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    cout << "\n\n";
}

void insert_test(){
    cout << "***** insert_test *****\n";
    insert(0, 10); // 10, len = 1, capacity = 1
    print_arr();
    insert(0, 30); // 30 10, len = 2, capacity = 2
    print_arr();
    insert(1, 20); // 30 20 10, len = 3, capacity = 4
    print_arr();
    insert(3, 40); // 30 20 10 40, len = 4, capacity = 4
    print_arr();
    insert(1, 50); // 30 50 20 10 40, len = 5, capacity = 8
    print_arr();
    insert(0, 15); // 15 30 50 20 10 40, len = 6, capacity = 8
    print_arr();
}

int main() {
    init();
    insert_test();
}