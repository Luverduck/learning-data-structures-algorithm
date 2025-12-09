#include <stdio.h>

typedef struct _empInfo
{
    int empNo;     // 직원의 사번
    int age;       // 직원의 나이
} EmpInfo;

int GetHashValue(int empNo)
{
    return empNo % 100;
}

int main()
{
    EmpInfo empInfoArr[100];

    EmpInfo emp1 = { 20120003, 42 };
    EmpInfo emp2 = { 20130012, 33 };
    EmpInfo emp3 = { 20170049, 27 };

    EmpInfo target1, target2, target3;

    // 해시 함수로 구한 값을 키로 하여 테이블에 저장
    empInfoArr[GetHashValue(emp1.empNo)] = emp1;
    empInfoArr[GetHashValue(emp2.empNo)] = emp2;
    empInfoArr[GetHashValue(emp3.empNo)] = emp3;

    // 키를 인덱스의 값으로 데이터 탐색
    target1 = empInfoArr[GetHashValue(20120003)];
    target2 = empInfoArr[GetHashValue(20130012)];
    target3 = empInfoArr[GetHashValue(20170049)];

    // 탐색 결과 확인
    printf("사번 : %d, 나이 : %d\n", target1.empNo, target1.age);
    printf("사번 : %d, 나이 : %d\n", target2.empNo, target2.age);
    printf("사번 : %d, 나이 : %d\n", target3.empNo, target3.age);
}