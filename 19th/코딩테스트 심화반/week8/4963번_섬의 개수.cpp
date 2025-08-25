#include <iostream>

using namespace std;

int w, h;

// 플러드필
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int map[51][51];
bool visited[51][51];

// 연결된 모든 섬을 visited로 바꾸는 DFS
void dfs(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (0 < nr && nr <= h && 0 < nc && nc <= w) {
            // 방문하지 않았고, 섬일 경우
            if (!visited[nr][nc] && map[nr][nc] != 0) {
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }   
    }
}

int main() {
    while(1) {
        cin >> w >> h;
        
        if (w == 0 && h == 0) break;
        
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }
        
        int count = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                // 방문하지 않았고, 섬일 경우
                if (!visited[i][j] && map[i][j] != 0) {
                    visited[i][j] = true;
                    dfs(i, j);
                    count++;
                }               
            }
        }
        cout << count << "\n";  

        // 다음 테스트 케이스를 위해 map과 visited 배열 정리
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
}