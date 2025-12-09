// Chapter 10. 정렬 (Sorting)
// 10-1. 단순한 정렬 알고리즘

#include <stdio.h>

// 버블 정렬
// - 인접한 두 데이터를 비교하여 정렬
void BubbleSort(int arr[], int n)
{
    // 데이터 교환을 위한 임시 메모리
    int temp;
    // 버블 정렬
    for (int i = 0; i < n; ++i) // n개의 요소 순회
    {
        for (int j = 0; j < n - i; ++j)
        {
            // j번째 요소가 j+1번째 요소보다 클 경우
            if (arr[j] > arr[j + 1])
            {
                // 데이터 교환
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = { 3, 2, 4, 1 };

    BubbleSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}