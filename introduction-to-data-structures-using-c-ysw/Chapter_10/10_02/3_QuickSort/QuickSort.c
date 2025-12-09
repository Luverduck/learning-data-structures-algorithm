#include <stdio.h>

// 두 데이터의 위치 변경
void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
};

// 피벗을 기준으로 데이터 영역 분할
int Partition(int arr[], int left, int right)
{
    // 가장 왼쪽의 데이터를 피벗으로 설정
    int pivot = arr[left];
    // 피벗보다 작은 값 영역의 인덱스
    int lowIDX = left + 1;
    // 피벗보다 큰 값 영역의 인덱스
    int highIDX = right;
    // 두 영역의 인덱스가 교차되지 않을 때까지 반복
    while (lowIDX <= highIDX)
    {
        // [수정] 피벗보다 크거나 같은 값을 만날 때까지 반복
        while (arr[lowIDX] <= pivot && lowIDX <= right) // lowIDX의 상한
            lowIDX++;
        // [수정] 피벗보다 작거나 같은 값을 만날 때까지 반복
        while (arr[highIDX] >= pivot && highIDX >= (left + 1)) // highIDX의 하한
            highIDX--;
        // 교차되지 않은 상태라면 두 데이터의 위치 교환
        if (lowIDX <= highIDX)
            Swap(arr, lowIDX, highIDX);
    }
    // 피벗과 highIDX가 가리키는 데이터의 위치 교환
    Swap(arr, left, highIDX);
    // 옮겨진 피벗의 위치 반환
    return highIDX;
};

// 퀵 정렬
// - 피벗을 기준으로 피벗보다 작은 값 / 큰 값으로 영역을 나누어 정렬
void QuickSort(int arr[], int left, int right)
{
    // 재귀 호출 중 'left <= pivot - 1'과 'pivot + 1 <= right'를 만족하는 경우에만 실행
    if (left <= right)
    {
        // 피벗 위치 결정
        int pivot = Partition(arr, left, right);
        // 피벗을 기준으로 왼쪽 영역 퀵 정렬
        QuickSort(arr, left, pivot - 1);
        // 피벗을 기준으로 오른쪽 영역 퀵 정렬
        QuickSort(arr, pivot + 1, right);
    }
};

int main()
{
    //int arr[] = { 3, 2, 4, 1, 7, 6, 5 };
    int arr[] = {3, 3, 3};
    int len = sizeof(arr) / sizeof(int);

    QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);

    return 0;
};