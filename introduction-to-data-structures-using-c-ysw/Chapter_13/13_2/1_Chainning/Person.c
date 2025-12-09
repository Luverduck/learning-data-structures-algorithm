#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

// 주민등록번호 반환 (Key 반환)
int GetSSN(Person* p)
{
    return p->ssn;
};

// 신상 정보 출력
void ShowPersonInfo(Person* p)
{
    printf("주민등록번호 : %d\n", p->ssn);
    printf("이름 : %s\n", p->name);
    printf("주소 : %s\n", p->addr);
};

// 신상 정보 생성
Person* MakePersonData(int ssn, char* name, char* addr)
{
    // 메모리 동적 할당
    Person* newP = (Person*)malloc(sizeof(Person));
    // 멤버 설정
    newP->ssn = ssn;
    strcpy(newP->name, name); // 문자열 복사
    strcpy(newP->addr, addr); // 문자열 복사
    // 설정된 신상 정보 반환
    return newP;
};