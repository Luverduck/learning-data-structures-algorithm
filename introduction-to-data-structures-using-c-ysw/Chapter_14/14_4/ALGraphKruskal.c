#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

// 정렬 함수
int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;   // data1이 앞에 위치한다.
    else
        return 1;   // data2가 앞에 위치한다.
}

// 우선순위 비교 함수
int PQWeightComp(Edge data1, Edge data2)
{
    return data1.weight - data2.weight;
}

// 가중치 그래프의 초기화
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
    // 우선순위 큐의 초기화
    PQueueInit(&(pgraph->pqueue), PQWeightComp);
};

// 가중치 그래프의 메모리 해제
void GraphDestroy(ALGraph* pgraph)
{
    if (pgraph->adjList != NULL)
        free(pgraph->adjList);
    
    if (pgraph->visitInfo != NULL)
        free(pgraph->visitInfo);
};

// 가중치를 고려한 간선의 추가
void AddEdge(ALGraph* pgraph, int fromV, int toV, int weight)
{
    // 간선 생성 및 초기화
    Edge edge = { fromV, toV, weight };
    // 간선에 의해 연결된 두 정점을 인접 리스트에 각각 추가
    LInsert(&(pgraph->adjList[fromV]), toV);
    LInsert(&(pgraph->adjList[toV]), fromV);
    // 간선의 갯수 증가
    pgraph->numE += 1;
    // 간선의 가중치 정보를 우선순위 큐에 추가
    PEnqueue(&(pgraph->pqueue), edge);    
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

// 한 쪽 방향의 간선 삭제
void RemoveWayEdge(ALGraph* pgraph, int fromV, int toV)
{
    // 변수 선언
    int targetV; // 탐색한 정점
    // fromV에 연결된 첫 번째 정점에 대하여
    if (LFirst(&(pgraph->adjList[fromV]), &targetV))
    {
        // 첫 번째 정점이 삭제할 간선에 연결된 정점일 경우
        if (targetV == toV)
        {
            // fromV와의 연결 삭제 (간선 삭제)
            LRemove(&(pgraph->adjList[fromV]));
            return;
        }
        // 그 다음 정점들에 대하여
        while (LNext(&(pgraph->adjList[fromV]), &targetV))
        {
            // 그 다음 정점이 삭제할 간선에 연결된 정점일 경우
            if (targetV == toV)
            {
                // fromV와의 연결 삭제 (간선 삭제)
                LRemove(&(pgraph->adjList[fromV]));
                return;
            }
        }
    }
};

// 간선 삭제
void RemoveEdge(ALGraph* pgraph, int fromV, int toV)
{
    // fromV에서 toV 방향 간선 삭제
    RemoveWayEdge(pgraph, fromV, toV);
    // toV에서 fromV 방향 간선 삭제
    RemoveWayEdge(pgraph, toV, fromV);
    // 간선의 수 감소
    (pgraph->numE)--;
};

// 삭제된 간선을 다시 삽입
void RecoverEdge(ALGraph* pgraph, int fromV, int toV, int weight)
{
    // fromV에서 toV 방향 간선 삽입 (연결 리스트 추가)
    LInsert(&(pgraph->adjList[fromV]), toV);
    // toV에서 fromV 방향 간선 삽입 (연결 리스트 추가)
    LInsert(&(pgraph->adjList[toV]), fromV);
    // 간선의 수 증가
    (pgraph->numE)++;
}

// 두 정점이 연결되어 있는지 확인
int IsConnectedVertex(ALGraph* pgraph, int vertex1, int vertex2)
{
    // 변수의 선언
    Stack stack;
    int visitV = vertex1;
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

        // 첫 번째 정점이 연결 여부를 확인하려는 정점일 경우 (연결되어있는 경우)
        if (nextV == vertex2)
        {
            // 반환하기 전 방문한 정점 배열의 모든 요소를 0으로 초기화
            memset(pgraph->visitInfo, 0, sizeof(int) * pgraph->numV);
            // '연결되어 있음'(TRUE) 반환
            return TRUE;
        }

        // 정점의 방문에 성공한 경우
        if (VisitVertex(pgraph, nextV) == TRUE)
        {
            // 방문한 정점의 정보를 스택에 저장
            SPush(&stack, visitV);
            // 방문한 정점을 현재 정점으로 변경
            visitV = nextV;
            // 방문 여부를 TRUE로 변경
            visitFlag = TRUE;
        }
        // 이미 방문한 정점일 경우
        else
        {
            // 현재 정점에 연결된 다음 정점이 NULL이 아닐 경우
            while (LNext(&(pgraph->adjList[visitV]), &nextV) == TRUE)
            {
                // 다음 정점이 연결 여부를 확인하려는 정점일 경우 (연결되어있는 경우)
                if (nextV == vertex2)
                {
                    // 반환하기 전 방문한 정점 배열의 모든 요소를 0으로 초기화
                    memset(pgraph->visitInfo, 0, sizeof(int) * pgraph->numV);
                    // '연결되어 있음'(TRUE) 반환
                    return TRUE;
                }
                // 정점의 방문에 성공한 경우
                if (VisitVertex(pgraph, nextV) == TRUE)
                {
                    // 방문한 정점의 정보를 스택에 저장
                    SPush(&stack, visitV);
                    // 방문한 정점을 현재 정점으로 변경
                    visitV = nextV;
                    // 방문 여부를 TRUE로 변경
                    visitFlag = TRUE;
                    // 현재 정점에 연결된 정점 탐색 중지
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
    // 반환하기 전 방문한 정점 배열의 모든 요소를 0으로 초기화
    memset(pgraph->visitInfo, 0, sizeof(int) * pgraph->numV);
    // '연결되어있지 않음'(FALSE) 반환
    return FALSE;
}

// 최소 신장 트리 구성 (Kruskal 알고리즘 기반)
void ConstructKruskalMST(ALGraph* pgraph)
{
    // 변수 선언 및 초기화
    Edge edge;                  // 우선순위 큐에서 꺼낸 간선의 정보
    Edge recoverEdgeArray[20];  // 복원할 간선 배열
    int eIdx = 0;               // 복원할 간선 배열의 인덱스
    // 최소 신장 트리를 구성할 때까지 반복
    while (pgraph->numE + 1 > pgraph->numV) // '간선의 수 + 1 == 정점의 수'를 만족할 때 MST
    {
        // 우선순위 큐에서 가중치가 가장 큰 간선의 정보를 꺼냄
        edge = PDequeue(&(pgraph->pqueue));
        // 우선순위 큐에서 꺼낸 간선을 그래프에서 삭제
        RemoveEdge(pgraph, edge.vertex1, edge.vertex2);
        // 간선 삭제 후 두 정점이 연결되어있지 않다면
        if (!IsConnectedVertex(pgraph, edge.vertex1, edge.vertex2))
        {
            // 삭제한 간선 복원
            RecoverEdge(pgraph, edge.vertex1, edge.vertex2, edge.weight);
            // 복원한 간선의 정보를 복원할 간선 배열에 저장
            recoverEdgeArray[eIdx] = edge;
            // 복원할 간선 배열의 인덱스 증가
            eIdx++;
        }
    }
    // 복원할 간선 배열을 통해 우선순위 큐 복원
    for (int i = 0; i < eIdx; ++i)
        PEnqueue(&(pgraph->pqueue), recoverEdgeArray[i]);
};

// 가중치 정보 출력
void ShowGraphEdgeWeightInfo(ALGraph* pgraph)
{
    PQueue copyPQueue = pgraph->pqueue;
    Edge edge;

    while (!PQIsEmpty(&copyPQueue))
    {
        edge = PDequeue(&copyPQueue);
        printf("(%c-%c), w : %d\n", edge.vertex1 + 65, edge.vertex2 + 65, edge.weight);
    }
};