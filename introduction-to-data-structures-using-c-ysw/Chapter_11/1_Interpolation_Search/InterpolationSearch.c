// Chapter 11. 탐색 (Search)
// 11-1. 탐색의 이해와 보간 탐색

#include <stdio.h>

// 보간 탐색 (Interpolation Search)
// - 이진 탐색을 개선한 것으로 수치 해석학의 보간법(Interpolation)을 사용한 탐색 방법
// - 이진 탐색과 달리 탐색 위치를 보간법으로 결정한다.
// - 이진 탐색과 마찬가지로 탐색 대상이 정렬되어 있어야 한다.
int InterpolationSearch(int arr[], int low, int high, int target)
{
    // 탐색 위치
    int mid;
    // 재귀 호출로 인해 탐색 범위를 벗어나게 될 경우
    if (arr[low] > target || arr[high] < target)
        return -1;  // 탐색 실패
    // 보간법을 통한 탐색 위치 결정
    mid = (((double)(target - arr[low])) / (arr[high] - arr[low]) * (high - low)) + low;
    // 보간 탐색
    if (arr[mid] == target) // 찾으려는 값과 탐색 대상이 일치하는 경우
        return mid; // 탐색 성공 및 해당 데이터의 인덱스 반환
    else if (arr[mid] > target) // 찾으려는 값이 더 큰 경우
        InterpolationSearch(arr, low, mid - 1, target); // 탐색 범위 축소 (low ~ mid-1)
    else // 찾으려는 값이 더 작은 경우
        InterpolationSearch(arr, mid + 1, high, target); // 탐색 범위 변경 (mid+1 ~ high)
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9 };
    int target = 2; // 없는 데이터를 탐색하는 경우

    int idx;
    idx = InterpolationSearch(arr, 0, sizeof(arr)/sizeof(int), target);

    if (idx == -1)
        printf("탐색 실패!");
    else
        printf("%d(이)가 저장된 인덱스 : %d", target, idx);

    return 0;
}