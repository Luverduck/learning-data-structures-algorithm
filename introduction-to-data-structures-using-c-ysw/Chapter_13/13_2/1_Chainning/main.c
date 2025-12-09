
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table table;
    Person* nPerson;
    Person* sPerson;
    Person* rPerson;

    TBLInit(&table, MyHashFunc);

    // 데이터 입력
    nPerson = MakePersonData(900254, "LEE", "Seoul");
    TBLInsert(&table, GetSSN(nPerson), nPerson);

    nPerson = MakePersonData(900139, "KIM", "Jeju");
    TBLInsert(&table, GetSSN(nPerson), nPerson);

    nPerson = MakePersonData(900827, "HAN", "Kangwon");
    TBLInsert(&table, GetSSN(nPerson), nPerson);

    // 테이블 탐색
    sPerson = TBLSearch(&table, 900254);
    if (sPerson != NULL)
        ShowPersonInfo(sPerson);

    sPerson = TBLSearch(&table, 900139);
    if (sPerson != NULL)
        ShowPersonInfo(sPerson);

    sPerson = TBLSearch(&table, 900827);
    if (sPerson != NULL)
        ShowPersonInfo(sPerson);

    // 데이터 삭제
    rPerson = TBLDelete(&table, 900254);
    if (rPerson != NULL)
        free(rPerson);

    rPerson = TBLDelete(&table, 900139);
    if (rPerson != NULL)
        free(rPerson);

    rPerson = TBLDelete(&table, 900827);
    if (rPerson != NULL)
        free(rPerson);

    return 0;
}