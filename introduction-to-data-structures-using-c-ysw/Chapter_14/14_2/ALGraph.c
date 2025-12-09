#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

// 정렬 함수의 함수 원형
int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph* pgraph, int numV)
{
    // 정점의 수 초기화
    pgraph->numV = numV;
    // 간선의 수 초기화 (초기에는 0)
    pgraph->numE = 0;
    // 정점의 수에 해당하는 길이의 리스트 배열 생성
    pgraph->adjList = (List*)malloc(sizeof(List) * numV);
    // 리스트 배열 초기화
    for(int i = 0; i < numV; ++i)
    {
        // 리스트 초기화
        ListInit(&(pgraph->adjList[i]));
        // 리스트의 정렬 규칙 설정
        SetSortRule(&(pgraph->adjList[i]), WhoIsPrecede);
    }
};

// 그래프의 메모리 해제
void GraphDestroy(ALGraph* pgraph)
{
    if (pgraph->adjList != NULL)
        free(pgraph->adjList);
};

// 간선의 추가
void AddEdge(ALGraph* pgraph, int fromV, int toV)
{
    // 두 정점을 서로 연결
    LInsert(&(pgraph->adjList[fromV]), toV);
    LInsert(&(pgraph->adjList[toV]), fromV);
    // 간선의 수 증가
    pgraph->numE += 1;
};

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pgraph)
{
    // 선택한 정점
    int cVertex;
    // 그래프의 모든 정점을 순회
    for (int i = 0; i < pgraph->numV; ++i)
    {
        printf("%c와 연결된 정점 : ", i + 65); // 문자 'A'는 정수 65이다.
        // 정점에 연결된 리스트의 첫 번째 요소가 NULL이 아닐 경우
        if (LFirst(&(pgraph->adjList[i]), &cVertex))
        {
            // 첫 번째 요소의 값 출력
            printf("%c ", cVertex + 65);
            // 다음 요소가 NULL일 때까지 요소의 값 출력
            while (LNext(&(pgraph->adjList[i]), &cVertex))
                printf("%c ", cVertex + 65);
        }
        printf("\n");
    }
};

// 정렬 함수의 함수 정의
int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;   // data1이 앞에 위치한다.
    else
        return 1;   // data2가 앞에 위치한다.
}