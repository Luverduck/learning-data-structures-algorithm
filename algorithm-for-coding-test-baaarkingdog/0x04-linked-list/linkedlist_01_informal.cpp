#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; // 다음 요소가 추가될 주소

// 요소 추가 : addr 위치 뒤에 num을 추가
void insert(int addr, int num)
{
    // 1. 요소 추가 및 해당 요소의 이전, 다음 요소 주소 저장
    // 요소 추가 (데이터 저장)
    dat[unused] = num;
    // 추가한 요소의 이전 요소 주소를 addr로 변경
    pre[unused] = addr;
    // 추가한 요소의 다음 요소 주소를 기존 addr 요소의 다음 요소 주소로 변경
    nxt[unused] = nxt[addr];
    // 2. 기존 요소들의 다음, 이전 요소 주소 조정
    // addr 위치의 다음 요소의 이전 요소 주소를 unused로 변경
    // - addr 위치의 다음 요소가 더미 노드일 경우에 대한 처리 추가
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    // addr 위치의 이전 요소의 다음 요소 주소를 unused로 변경
    nxt[addr] = unused;
    // unused 증가
    unused++;
}

// 요소 삭제 (addr 위치 요소 삭제)
void erase(int addr)
{
    // addr 위치의 이전 요소의 다음 요소 주소를 addr 위치의 다음 요소로 변경
    nxt[pre[addr]] = nxt[addr];
    // addr 위치의 다음 요소의 이전 요소 주소를 addr 위치의 이전 요소로 변경
    // - addr 위치의 다음 요소가 더미 노드일 경우에 대한 처리
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n";
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}