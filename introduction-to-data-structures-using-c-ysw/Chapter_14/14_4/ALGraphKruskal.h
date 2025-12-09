#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

// 정점의 이름 상수화
enum { A, B, C, D, E, F, G, H, I, J };

// 그래프의 정의
typedef struct _ual
{
    int numV;       // 정점의 수
    int numE;       // 간선의 수
    List* adjList;  // 간선의 정보
    int* visitInfo; // 방문한 정점의 배열
    PQueue pqueue;  // 간선의 가중치 정보 저장
} ALGraph;

// 가중치 그래프의 초기화
void GraphInit(ALGraph* pgraph, int numV);

// 가중치 그래프의 메모리 해제
void GraphDestroy(ALGraph* pgraph);

// 가중치를 고려한 간선의 추가
void AddEdge(ALGraph* pgraph, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pgraph);

// 정점의 정보 출력 (DFS 기반)
void DFShowGraphVertex(ALGraph* pgraph, int startV);

// 최소 신장 트리 구성 (Kruskal 알고리즘 기반)
void ConstructKruskalMST(ALGraph* pgraph);

// 가중치 정보 출력
void ShowGraphEdgeWeightInfo(ALGraph* pgraph);

#endif