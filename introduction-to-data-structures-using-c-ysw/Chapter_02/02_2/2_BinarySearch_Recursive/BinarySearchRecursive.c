// Chapter 02. 재귀 (Recursion)
// 02-2. 재귀의 활용
/*
    재귀 호출로 구현한 이진 탐색
    - 이진 탐색의 반복 패턴 (재귀 패턴)
        1. 현재 탐색 범위의 중앙에 대상이 저장되어 있는지 확인
        2. 저장되지 않았다면 탐색 범위를 반으로 줄여서 다시 탐색
    - 이진 탐색의 탐색 실패 조건 (재귀의 탈출 조건)
        탐색 범위의 시작 위치가 끝 위치보다 커지는 경우 탐색 실패
*/

// 이진 탐색
int binarySearchRecursive(int* arr, int first, int last, int target)
{
    // 재귀의 탈출 조건
    if (first > last) return -1;
    // 현재 단계에서 중앙의 값
    int mid = (first + last) / 2;
    // 재귀 호출로 구현한 이진 탐색
    if(target == arr[mid])
        return mid;
    else if(target > arr[mid])
        return binarySearchRecursive(arr, mid + 1, last, target);
    else
        return binarySearchRecursive(arr, first, mid - 1, target);
}

#include <stdio.h>
int main()
{
    int arr[] = { 1, 3, 5, 7, 9 };
    int target = 9;
    int idx;
    
    // 이진 탐색
    idx = binarySearchRecursive(arr, 0, sizeof(arr) / sizeof(int), target);

    // 결과
    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("발견한 요소의 인덱스 : %d\n", idx);

    return 0;
}