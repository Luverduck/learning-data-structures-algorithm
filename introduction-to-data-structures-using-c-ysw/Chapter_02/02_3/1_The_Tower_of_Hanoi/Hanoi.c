// Chapter 02. 재귀 (Recursion)
// 02-3. 하노이 타워 (The Tower of Hanoi)
/*
    하노이 타워
*/

// 원반 이동 횟수
static int count = 0;

// 원반 이동 (num개의 원반을 by를 이용하여 from에서 to로 이동)
#include <stdio.h>
void hanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1)   // 이동할 원반 갯수가 1개일 때
    {
        // from에서 to로 바로 옮기기
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
        count++;
    }
    else            // 이동할 원반 갯수가 여러 개일 때
    {
        // 1) (n-1)개의 원반을 by에 옮기기
        hanoiTowerMove(num - 1, from, to, by);
        // 2) from에 있는 가장 하단의 원반을 to에 옮기기
        printf("원반 %d을 %c에서 %c로 이동\n", num, from, to);
        count++;
        // 3) by에 있는 (n-1)개의 원반을 to에 옮기기
        hanoiTowerMove(num - 1, by, from, to);
    }
}

int main()
{
    // 기둥 A의 원반 3개를 기둥 B를 경유하여 기둥 C로 옮기기
    hanoiTowerMove(3, 'A', 'B', 'C');

    // 결과
    printf("원반 이동 횟수 : %d", count);

    return 0;
};