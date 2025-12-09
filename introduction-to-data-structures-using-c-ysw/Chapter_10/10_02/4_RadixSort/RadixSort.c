#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM      10

void RadixSort(int data[], int num, int maxLen)
{
    // 변수 할당
    int radix;      // 자릿수
    int divfac = 1; // 제수 (Devidend)
    int dataIDX;     // 배열 인덱스
    int bucketIDX;  // 버킷 인덱스
    int pos;        // 데이터의 길이 인덱스

    // 10개의 버킷(큐) 생성
    Queue buckets[BUCKET_NUM];
    // 생성한 10개의 버킷 초기화
    for (bucketIDX = 0; bucketIDX < BUCKET_NUM; ++bucketIDX)
        QueueInit(&buckets[bucketIDX]);

    // 가장 긴 데이터의 길이만큼 반복
    for (pos = 0; pos < maxLen; ++pos)
    {
        // 정렬할 데이터의 수만큼 반복
        for (dataIDX = 0; dataIDX < num; ++dataIDX)
        {
            // N번째 자릿수 추출
            radix = (data[dataIDX] / divfac) % 10;
            // 추출한 숫자에 해당하는 버킷에 데이터 저장
            Enqueue(&buckets[radix], data[dataIDX]);
        }
        // data의 인덱스 초기화 (배열에 데이터 저장을 위한 초기화)
        dataIDX = 0;
        // 버킷 수만큼 반복
        for (bucketIDX = 0; bucketIDX < BUCKET_NUM; ++bucketIDX)
        {
            // 버킷이 비어있을 때까지 반복
            while (!QIsEmpty(&buckets[bucketIDX])) 
            {
                // 각각의 버킷에 저장된 데이터를 data에 저장(선입선출)
                data[dataIDX] = Dequeue(&buckets[bucketIDX]);
                // data의 인덱스 증가
                dataIDX++;
            }
        }
        // N+1번째 자릿수 추출을 위한 제수(dividend) 변경
        divfac *= 10;
    }
}

int main()
{
    // 정렬할 데이터 그룹
    int arr[] = { 13, 212, 14, 7141, 10987, 6, 15 };
    // 데이터 그룹의 길이
    int arrLen = sizeof(arr) / sizeof(int);
    // 기수 정렬
    RadixSort(arr, arrLen, 5);
    // 정렬된 데이터 그룹의 요소 출력
    for (int i = 0; i < arrLen; ++i)
        printf("%d ", arr[i]);

    return 0;
}