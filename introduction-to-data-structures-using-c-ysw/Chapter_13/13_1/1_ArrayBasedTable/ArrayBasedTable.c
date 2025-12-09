// Chapter 13. 테이블(Table)과 해시(Hash)
// 13-1. 빠른 탐색을 보이는 해시 테이블

#include <stdio.h>

// 테이블로 정의한 직원 정보
typedef struct _empInfo
{
    int empNo;     // 직원의 고유 번호
    int age;        // 직원의 나이
} EmpInfo;

int main()
{
    EmpInfo empInfoArr[1000];
    EmpInfo empInfo;
    int empNoSearch;

    printf("사번과 나이 입력 : ");
    scanf("%d %d", &(empInfo.empNo), &(empInfo.age));
    empInfoArr[empInfo.empNo] = empInfo;

    printf("확인할 직원의 사번 : ");
    scanf("%d", &empNoSearch);

    empInfo = empInfoArr[empNoSearch];
    printf("사번 : %d, 나이 : %d\n", empInfo.empNo, empInfo.age);

    return 0;
}