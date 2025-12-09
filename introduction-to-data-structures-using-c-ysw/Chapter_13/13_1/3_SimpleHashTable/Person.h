#ifndef __PERSON_H__
#define __PERSON_H__

// 문자열의 길이
#define STR_LEN 50

// 신상 정보 (테이블에 저장할 데이터의 자료형)
typedef struct _person
{
    int ssn;            // 주민등록번호
    char name[STR_LEN]; // 이름
    char addr[STR_LEN]; // 주소
} Person;

// 주민등록번호 반환 (Key 반환)
int GetSSN(Person* p);

// 신상 정보 출력
void ShowPersonInfo(Person* p);

// 신상 정보 생성
Person* MakePersonData(int ssn, char* name, char* addr);

#endif