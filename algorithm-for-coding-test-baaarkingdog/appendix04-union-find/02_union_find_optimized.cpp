#include <bits/stdc++.h>

using namespace std;

// 부모 정점의 정점 번호를 저장하는 벡터
vector<int> p(11, -1);

// 파인드 연산
int uf_find(int x)
{
    // 루트 정점 도달 시 정점 번호 반환
    if (p[x] < 0) return x;
    //
    return p[x] = uf_find(p[x]);
}

// 유니온 연산
bool uf_union(int u, int v)
{
    // u의 루트 정점 탐색
    u = uf_find(u);
    // v의 루트 정점 탐색
    v = uf_find(v);
    // u와 v가 같을 경우(같은 그룹) false 반환
    if (u == v) return false;
    // v의 루트 정점 랭크가 더 작은 경우 (v가 루트 정점인 트리가 더 높은 경우)
    if (p[u] > p[v])
        // u와 v를 서로 바꿈 (높은 트리가 부모가 되도록)
        swap(u, v);
    // u의 루트 정점 랭크와 v의 루트 정점 랭크가 같은 경우
    if (p[u] == p[v])
        // u의 루트 정점 랭크 감소
        p[u]--;
    // u를 v의 부모 정점으로 설정
    p[v] = u;
    // true 반환
    return true;
}

int main() {

}