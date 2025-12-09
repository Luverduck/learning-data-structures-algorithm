#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

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
    // 방문한 정점의 배열 생성 및 초기화
    pgraph->visitInfo = (int*)malloc(sizeof(int) * pgraph->numV);
    memset(pgraph->visitInfo, 0, (sizeof(int) * pgraph->numV));
};

// 그래프의 메모리 해제
void GraphDestroy(ALGraph* pgraph)
{
    if (pgraph->adjList != NULL)
        free(pgraph->adjList);
    
    if (pgraph->visitInfo != NULL)
        free(pgraph->visitInfo);
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

// 정점의 방문
int VisitVertex(ALGraph* pgraph, int visitV)
{
    // 한 번도 방문하지 않은 정점이라면
    if (pgraph->visitInfo[visitV] == 0)
    {
        // '방문' 상태로 변경
        pgraph->visitInfo[visitV] = 1;
        // 정점의 정보 출력
        printf("%c ", visitV + 65);
        // TRUE 반환
        return TRUE;
    }
    // FALSE 반환
    return FALSE;
}

// 정점의 정보 출력 (DFS 기반)
void DFShowGraphVertex(ALGraph* pgraph, int startV)
{
    // 변수 선언
    Stack stack;
    int visitV = startV;
    int nextV;
    // 스택 초기화
    StackInit(&stack);
    // 시작 정점의 방문
    VisitVertex(pgraph, visitV);
    // 시작 정점의 정보를 스택에 저장
    SPush(&stack, visitV);
    // 현재 정점에 연결된 첫 번째 정점이 NULL이 아닐 경우
    while (LFirst(&(pgraph->adjList[visitV]), &nextV) == TRUE)
    {
        // 정점의 방문 여부를 FALSE로 초기화
        int visitFlag = FALSE;
        if (VisitVertex(pgraph, nextV) == TRUE) // 정점 방문에 성공한 경우
        {
            // 스택에 정점의 정보 저장
            SPush(&stack, nextV);
            // 방문한 정점을 현재 정점으로 변경
            visitV = nextV;
            // 방문 여부를 TRUE로 변경
            visitFlag = TRUE;
        }
        else // 정점 방문에 실패한 경우 (이미 방문한 정점)
        {
            // 그 다음 정점을 순차적으로 확인
            while (LNext(&(pgraph->adjList[visitV]), &nextV) == TRUE)
            {
                if (VisitVertex(pgraph, nextV) == TRUE) // 정점 방문에 성공한 경우
                {
                    // 스택에 정점의 정보 저장
                    SPush(&stack, nextV);
                    // 방문한 정점을 현재 정점으로 변경
                    visitV = nextV;
                    // 방문 여부를 TRUE로 변경
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        // 정점의 방문 여부가 FALSE일 경우
        if (visitFlag == FALSE)
        {
            if (SIsEmpty(&stack) == TRUE) // 스택이 비어있다면
                break; // 탐색 완료
            else // 스택이 비어있지 않다면
                visitV = SPop(&stack); // 스택에서 정점을 꺼내서 다음 방문할 노드로 설정
        }
    }
    // 방문한 정점의 배열의 모든 요소를 0으로 초기화
    memset(pgraph->visitInfo, 0, (sizeof(int) * pgraph->numV));
};

// 정렬 함수의 함수 정의
int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;   // data1이 앞에 위치한다.
    else
        return 1;   // data2가 앞에 위치한다.
}