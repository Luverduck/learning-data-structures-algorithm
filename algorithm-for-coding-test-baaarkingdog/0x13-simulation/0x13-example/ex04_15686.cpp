#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.acmicpc.net/problem/15686
 */

// 도시 크기 N, 유지할 치킨집 수 M
int N, M;
// 도시 상태 배열
int board[52][52];
// 집의 위치를 저장할 벡터
vector<pair<int, int>> house;
// 치킨집의 위치를 저장할 벡터
vector<pair<int, int>> chicken;

void solution()
{
    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            // 집일 경우 house에 추가
            if (board[i][j] == 1) house.emplace_back(i, j);
            // 치킨집일 경우 chicken에 추가
            if (board[i][j] == 2) chicken.emplace_back(i, j);
        }
    }
    // 치킨집 상태를 모두 폐업(1)으로 초기화
    vector<int> brute(chicken.size(), 1);
    // M개를 제외한 나머지 치킨집 상태를 영업(0)으로 변경
    fill(brute.begin(), brute.begin() + chicken.size() - M, 0);
    // 도시의 치킨 거리를 최대값으로 초기화
    int mn = 0x7f7f7f7f;
    // 치킨집 상태를 변경하면서 치킨 거리의 최소값 탐색
    do
    {
        // 도시의 치킨 거리
        int dist = 0;
        for (auto h : house)
        {
            // 특정 집에서 가장 가까운 치킨집까지의 치킨 거리 계산
            int tmp = 0x7f7f7f7f;
            for (int i = 0; i < chicken.size(); ++i)
            {
                if (brute[i] == 0) continue;
                tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            // 도시의 치킨 거리에 가산
            dist += tmp;
        }
        // 현재 도시의 치킨 거리가 계산한 도시의 치킨 거리보다 작을 경우에만 갱신
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));
    // 출력
    cout << mn;
}

int main()
{
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}