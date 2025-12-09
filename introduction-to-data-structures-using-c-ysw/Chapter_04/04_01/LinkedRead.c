// Chapter 04. 연결 리스트 (Linked List) 2
// 04-1. 연결 리스트의 개념적인 이해

#include <stdio.h>
#include <stdlib.h>

// 리스트의 노드 정의
typedef struct _node
{
    int data;               // 저장된 데이터
    struct _node* next;     // 다음 노드의 주소
} Node;

int main()
{
    Node* head = NULL;      // 맨 앞 노드 주소
    Node* tail = NULL;      // 맨 뒤 노드 주소
    Node* cur = NULL;       // 노드의 커서

    Node* newNode = NULL;   // 새로 추가할 요소
    
    int readData;           // 저장할 값

    // 데이터를 입력받는 과정
    while (1)
    {
        printf("자연수 입력 : ");
        scanf("%d", &readData);
        if (readData < 1) 
            break;

        // 노드의 추가 과정
        newNode = (Node*)malloc(sizeof(Node));  // 메모리 동적 할당
        newNode->data = readData;               // 입력 데이터 저장
        newNode->next = NULL;                   // 다음 노드의 주소를 NULL로 초기화

        if (head == NULL)           // 추가할 위치가 맨 앞인 경우
            head = newNode;         // 현재 head가 가리키는 노드의 주소를 새로 추가된 노드의 주소로 초기화한다.
        else                        // 추가할 위치가 맨 앞이 아닌 경우
            tail->next = newNode;   // 현재 tail이 가리키는 노드의 멤버 next를 새로 추가된 노드의 주소로 초기화 한다.

        tail = newNode;             // 현재 tail이 가리키는 노드의 주소를 새로 추가된 노드의 주소로 초기화한다.
    }
    printf("\n");

    // 입력받은 데이터를 출력하는 과정
    printf("입력받은 데이터의 전체 출력!\n");
    if (head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다.\n");
    }
    else
    {
        cur = head;
        printf("%d ", cur->data);   // 첫 번째 데이터 출력
        
        while (cur->next != NULL)   // 두 번째 이후의 데이터 출력
        {
            cur = cur->next;        // 커서를 다음 노드로 변경
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");

    // 메모리 해제 과정
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node* delNode = head;
        Node* delNextNode = head->next;

        printf("%d을(를) 삭제합니다.\n", head->data);
        free(delNode);

        while (delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }

    return 0;
}