#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[501][501];
int dp[501][501];
vector<pair<int, pair<int, int>>> v;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            v.push_back({ map[i][j], {i, j} }); // 가장 큰 값부터 탐색하기 위해 벡터 사용
            dp[i][j] = 1; // 모든 점이 이동 경로의 도착 지점이 될 수 있음
        }
    }

    sort(v.begin(), v.end(), greater<>()); // 내림차순 정렬

    // 값이 큰 점부터 주변의 네 점을 탐색하여, 본인보다 큰 점이 있다면 경로를 늘림
    // 내림차순으로 수행하기에 본인보다 큰 점을 만났을 때, 해당 점의 값을 그대로 더하면 됨
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int r = v[i].second.first;
        int c = v[i].second.second;

        int max_value = dp[r][c]; // dp[r][c]에서 제일 많이 이동한 칸의 수를 저장
        for (int j = 0; j < 4; j++) {
            int nr = r + dr[j];
            int nc = c + dc[j];

            if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
                if (map[nr][nc] > map[r][c]) {
                    max_value = max(max_value, dp[r][c] + dp[nr][nc]);
                    
                }
            }
        }
        dp[r][c] = max_value;
        ans = max(ans, dp[r][c]); // 모든 점 중 제일 많이 이동한 칸의 수를 저장
    }

    cout << ans;
}