// Chapter 10. 정렬 (Sorting)
// 10-1. 단순한 정렬 알고리즘

#include <stdio.h>

// 삽입 정렬
// - 정렬할 데이터를 이미 정렬된 데이터 그룹에 삽입하여 정렬
void InsertSort(int arr[], int n)
{
    // 루프 카운터 (루프를 탈출할 때의 삽입 인덱스 사용을 위함)
    int i, j;
    // 삽입할 데이터
    int insData;
    // 삽입 정렬
    for (i = 1; i < n; ++i) // n개의 요소 순회
    {
        // 삽입할 데이터 선택
        insData = arr[i];
        // 삽입 위치 탐색
        for (j = i - 1; j >= 0; --j)
        {
            // j번째 데이터가 현재 최소값 인덱스의 데이터보다 큰 경우
            if (arr[j] > insData)
                arr[j + 1] = arr[j]; // 비교 대상을 한 칸씩 뒤로 밀기
            else // 삽입 위치를 찾은 경우
                break; // 루프 탈출
        }
        // 데이터 삽입 (루프를 탈출할 때의 삽입 인덱스)
        arr[j + 1] = insData;
    }
}

int main()
{
    int arr[] = { 3, 2, 4, 1 };

    InsertSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}