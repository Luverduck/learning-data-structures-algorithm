#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

// 테이블 슬롯의 구성 요소
typedef int Key;        // 키 (주민등록번호)
typedef Person* Value;  // 값 (신상 정보)
enum SlotStatus { EMPTY, DELETE, INUSE };   // 슬롯의 상태

// 테이블 슬롯의 정의
// [변경] 슬롯의 상태 삭제
typedef struct _slot
{
    Key key;
    Value value;
} Slot;

#endif