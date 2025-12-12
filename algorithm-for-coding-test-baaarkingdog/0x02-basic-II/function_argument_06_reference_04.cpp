#include <bits/stdc++.h>

using namespace std;

int comp1(vector<int> v1, vector<int> v2, int idx)
{
    return v1[idx] > v2[idx];
}

int comp2(vector<int>& ref_v1, vector<int>& ref_v2, int idx)
{
    return ref_v1[idx] > ref_v2[idx];
}

int main()
{
    clock_t start, end;

    vector<int> v1(100000000);
    vector<int> v2(100000000);

    // STL 컨테이너의 모든 요소를 깊은 복사하여 매개변수에 전달
    start = clock();
    comp1(v1, v2, 1000000);
    end = clock();
    cout << end - start << "[ms]\n";

    // STL 컨테이너의 모든 요소를 깊은 복사하는 과정 생략
    start = clock();
    comp2(v1, v2, 1000000);
    end = clock();
    cout << end - start << "[ms]\n";
}