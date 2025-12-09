#ifndef __POINT_H__
#define __POINT_H__

// 좌표 정보를 저장하는 구조체 Point 정의
typedef struct _point
{
    int xpos;
    int ypos;
} Point;

// Point의 xpos, ypos 값 설정
void SetPointPos(Point* ppos, int xpos, int ypos);

// Point의 xpos, ypos 값 출력
void ShowPointPos(Point* ppos);

// 두 Point의 비교
int PointComp(Point* pos1, Point* pos2);

#endif