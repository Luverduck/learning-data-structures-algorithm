#include <stdio.h>
#include "Point.h"

// Point의 xpos, ypos 값 설정
void SetPointPos(Point* ppos, int xpos, int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
};

// Point의 xpos, ypos 값 출력
void ShowPointPos(Point* ppos)
{
    printf("[%d, %d]\n", ppos->xpos, ppos->ypos);
};

// 두 Point의 비교
int PointComp(Point* ppos1, Point* ppos2)
{
    if (ppos1->xpos == ppos2->xpos && ppos1->ypos == ppos2->ypos)
        return 0;
    else if (ppos1->xpos == ppos2->xpos)
        return 1;
    else if (ppos1->ypos == ppos2->ypos)
        return 2;
    else
        return -1;
};