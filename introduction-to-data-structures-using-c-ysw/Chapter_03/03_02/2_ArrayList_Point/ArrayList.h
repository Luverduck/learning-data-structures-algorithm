#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

// [변경] Point 구조체를 사용하기 위해 Point.h 추가
#include "Point.h"

// '참' / '거짓'을 표현하기 위한 매크로
#define TRUE    1
#define FALSE   0

// 리스트의 길이
#define LIST_LEN 100

// [변경] 리스트에 저장되는 데이터의 자료형을 Point*로 변경
typedef Point* LData;

// 리스트의 정의
typedef struct __ArrayList
{
    LData arr[LIST_LEN];    // 데이터 저장 공간 (배열)
    int numOfData;          // 저장된 데이터의 수
    int curPosition;        // 리스트에서 참조한 데이터의 index
} ArrayList;
typedef ArrayList List;

// 초기화
void ListInit(List* plist);

// 삽입
void LInsert(List* plist, LData data);

// 조회
// - 리스트의 첫 번째 데이터
int LFirst(List* plist, LData* pdata);
// - 리스트의 첫 번째 이후 데이터
int LNext(List* plist, LData* pdata);

// 삭제
LData LRemove(List* plist);

// 리스트에 저장된 데이터의 갯수 반환
int LCount(List* plist);

#endif