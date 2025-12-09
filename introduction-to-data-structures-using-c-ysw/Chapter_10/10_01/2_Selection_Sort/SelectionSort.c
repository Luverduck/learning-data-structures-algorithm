// Chapter 10. 정렬 (Sorting)
// 10-1. 단순한 정렬 알고리즘

#include <stdio.h>

// 선택 정렬
// - 데이터를 하나씩 선택하여 순서에 맞게 정렬
void SelectionSort(int arr[], int n)
{
    // 데이터 교환을 위한 임시 메모리
    int temp;
    // 현재 루프에서 최소값의 인덱스
    int minIDX;
    // 선택 정렬
    for (int i = 0; i < n; ++i) // n개의 요소 순회
    {
        // 교환할 데이터의 인덱스 초기화
        minIDX = i;
        // 최소값 탐색
        for (int j = i + 1; j < n; ++j)
        {
            // j번째 데이터가 현재 최소값 인덱스의 데이터보다 작은 경우
            if (arr[j] < arr[minIDX])
            {
                // 인덱스 교체
                minIDX = j;
            };
        }
        // 데이터 교환
        temp = arr[minIDX];
        arr[minIDX] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = { 3, 2, 4, 1 };

    SelectionSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}