#include <stdio.h>
#include <stdlib.h>

// 정렬된 그룹을 결합하는 힘수
void MergeTwoArea(int arr[], int left, int mid, int right)
{
    // 왼쪽 영역의 인덱스
    int frontIDX = left;
    // 오른쪽 영역의 인덱스
    int rearIDX = mid + 1;
    // 정렬을 위한 배열 (정렬 배열)
    int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
    // 정렬을 위한 배열의 인덱스 (정렬 배열의 인덱스)
    int sortIDX = left;
    // 정렬된 두 영역의 결합
    while (frontIDX <= mid && rearIDX <= right)
    {
        // 왼쪽의 비교 요소가 더 작을 경우
        if (arr[frontIDX] <= arr[rearIDX])
        {
            // 왼쪽의 비교 요소를 정렬 배열에 복사
            sortArr[sortIDX] = arr[frontIDX];
            // 왼쪽 요소의 인덱스 증가
            frontIDX++;
        }
        // 오른쪽의 비교 요소가 더 작을 경우
        else
        {
            // 오른쪽의 비교 요소를 정렬 배열에 복사
            sortArr[sortIDX] = arr[rearIDX];
            // 오른쪽 요소의 인덱스 증가
            rearIDX++;
        }
        // 정렬 배열의 인덱스 증가
        sortIDX++;
    }
    // 왼쪽 영역의 모든 요소를 옮긴 경우
    if (frontIDX > mid)
    {
        // 오른쪽 영역의 모든 요소를 정렬 배열에 복사
        for (int i = rearIDX; i <= right; i++)
        {
            sortArr[sortIDX] = arr[i];
            sortIDX++;
        }
    }
    // 오른쪽 영역의 모든 요소를 옮긴 경우
    else
    {
        // 왼쪽 영역의 모든 요소를 정렬 배열에 복사
        for (int i = frontIDX; i <= mid; i++)
        {
            sortArr[sortIDX] = arr[i];
            sortIDX++;
        }
    }
    // 결합이 완료된 정렬 배열의 요소를 데이터 배열에 복사
    for (int i = left; i <= right; i++)
        arr[i] = sortArr[i];
    // 정렬 배열의 메모리 해제
    free(sortArr);
}

// 병합 정렬
// - 분할(Devide), 정복(Conquer), 결합(Combine)의 3단계 과정을 통한 정렬
// - 분할 : 정렬할 데이터 단위가 하나가 될 때까지 데이터 그룹을 분할한다.
// - 정복 : 나누었던 데이터 그룹을 두 그룹씩 묶어서 정렬한다.
// - 결합 : 정렬된 그룹을 두 그룹씩 묶어서 정렬된 그룹이 하나가 될 때까지 정복 과정을 반복한다.
void MergeSort(int arr[], int left, int right)
{
    // 중간 지점
    int mid;
    // 병합 정렬
    if (left < right) // left == right일 때 정렬할 데이터 단위가 하나이다.
    {
        // 중간 지점 계산
        mid = (left + right) / 2;
        // 병합 정렬
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        // 정렬된 두 그룹을 결합
        MergeTwoArea(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = { 3, 4, 2, 1, 7, 6, 5 };
    
    MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
        printf("%d ", arr[i]);

    return 0;
}