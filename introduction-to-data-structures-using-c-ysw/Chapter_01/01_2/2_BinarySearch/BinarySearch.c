// Chapter 01. 자료 구조와 알고리즘의 이해
// 01-2. 알고리즘의 성능 분석 방법

#include <stdio.h>

// 이진 탐색 (Binary Search)
int binarySearch(int* arr, int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;

    // first와 last가 만날 때까지 반복 (단, first == last일 경우에도 대상의 값과 일치하는 지 검증해야 함)
    while (first <= last)           
    {
        mid = (first + last) / 2;   // 현재 루프에서 탐색 대상의 중앙 index

        if (target == arr[mid])     // 대상을 발견할 경우
        {
            return mid;             // 현재 루프에서 중앙 index 반환
        }
        else if (target < arr[mid]) // 대상의 값이 중앙 index의 값보다 클 경우
        {
            last = mid - 1;         // 탐색의 끝(last)을 변경
        }
        else                        // 대상의 값이 중앙 index의 값보다 작을 경우
        {
            first = mid + 1;        // 탐색의 시작(first)을 변경 
        }
    }

    return -1;                      // 그 외 -1 반환
}

int main()
{
    int arr[] = { 3, 5, 2, 4, 9 };
    int target = 9;
    int idx;

    idx = binarySearch(arr, sizeof(arr) / sizeof(int) , target);

    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("발견한 요소의 인덱스 : %d\n", idx);

    return 0;
}