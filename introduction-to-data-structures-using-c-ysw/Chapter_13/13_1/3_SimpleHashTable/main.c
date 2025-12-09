#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int key)
{
    return key % 100;
};

int main()
{
    // 변수 선언
    Table table;
    Person* newPerson;
    Person* searchPerson;
    Person* removePerson;

    // 테이블 초기화
    TBLInit(&table, MyHashFunc);

    // 데이터 입력
    newPerson = MakePersonData(20120003, "LEE", "Seoul");
    TBLInsert(&table, GetSSN(newPerson), newPerson);

    newPerson = MakePersonData(20130012, "KIM", "Jeju");
    TBLInsert(&table, GetSSN(newPerson), newPerson);

    newPerson = MakePersonData(20170019, "HAN", "Kangwon");
    TBLInsert(&table, GetSSN(newPerson), newPerson);

    // 데이터 탐색
    searchPerson = TBLSearch(&table, 20120003);
    if (searchPerson != NULL)
        ShowPersonInfo(searchPerson);

    searchPerson = TBLSearch(&table, 20130012);
    if (searchPerson != NULL)
        ShowPersonInfo(searchPerson);

    searchPerson = TBLSearch(&table, 20170019);
    if (searchPerson != NULL)
        ShowPersonInfo(searchPerson);
    
    // 데이터 삭제
    removePerson = TBLDelete(&table, 20120003);
    if (removePerson != NULL)
        free(removePerson);

    removePerson = TBLDelete(&table, 20130012);
    if (removePerson != NULL)
        free(removePerson);

    removePerson = TBLDelete(&table, 20170019);
    if (removePerson != NULL)
        free(removePerson);

    return 0;
}