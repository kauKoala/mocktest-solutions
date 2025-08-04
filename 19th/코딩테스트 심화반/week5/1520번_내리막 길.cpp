#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501]; // dp[i][j]는 i, j에서 N, M까지 이동 가능한 모든 경로의 개수

int N, M;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

// dfs는 r, c에서 N, M까지의 이동 가능한 모든 경로의 개수를 반환
// 시간 초과를 막기 위해 메모이제이션
int dfs(int r, int c) {
    // 방문하지 않은 점은 dfs 실행
    if (dp[r][c] == -1) { 
        dp[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (1 <= nr && nr <= N && 1 <= nc && nc <= M) {
                if (map[nr][nc] < map[r][c]) {
                    dp[r][c] += dfs(nr, nc);
                }
            }
        }
    }

    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            dp[i][j] = -1; // 방문했었는지 확인하기 위함
        }
    }

    dp[N][M] = 1; // N, M에서 N, M으로 이동은 1번 가능

    cout << dfs(1, 1);
}