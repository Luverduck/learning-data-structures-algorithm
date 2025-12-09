// Chapter 01. 자료 구조와 알고리즘의 이해
// 01-2. 알고리즘의 성능 분석 방법

#include <stdio.h>

// 선형 탐색 (Linear Search)
int linearSearch(int* arr, int len, int target)
{
    // 첫 번째 요소부터 index를 증가시켜가며 순차 탐색
    for(int i = 0; i < len; ++i)
    {
        if(arr[i] == target)    // 대상을 발견하면
            return i;           // index를 반환
    }
    return -1;                  // 그 외 -1 반환
}

int main()
{
    int arr[] = { 3, 5, 2, 4, 9 };
    int target = 5;
    int idx;

    idx = linearSearch(arr, sizeof(arr) / sizeof(int) , target);

    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("발견한 요소의 인덱스 : %d\n", idx);

    return 0;
}