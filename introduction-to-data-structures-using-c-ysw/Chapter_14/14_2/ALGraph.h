#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

// 정점의 이름 상수화
enum { A, B, C, D, E, F, G, H, I, J };

// 그래프의 정의
typedef struct _ual
{
    int numV;       // 정점의 수
    int numE;       // 간선의 수
    List* adjList;  // 간선의 정보
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph* pgraph, int numV);

// 그래프의 메모리 해제
void GraphDestroy(ALGraph* pgraph);

// 간선의 추가
void AddEdge(ALGraph* pgraph, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pgraph);

#endif