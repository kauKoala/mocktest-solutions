#include <iostream>

using namespace std;

char map[101][101];
bool visited[101][101];

// 플러드필
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int H, W;

// 연결된 모든 양을 visited로 바꾸는 DFS
void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 < nr && nr <= H && 0 < nc && nc <= W) {
            // 방문하지 않았고, 양일 경우
            if (!visited[nr][nc] && map[nr][nc] == '#') {
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> H >> W;

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> map[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                // 방문하지 않았고, 양일 경우
                if (!visited[i][j] && map[i][j] == '#') {
                    visited[i][j] = true;
                    dfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << "\n";

        // 다음 테스트 케이스를 위해 map과 visited 배열 정리
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                map[i][j] = '.';
                visited[i][j] = false;
            }
        }
    }
}