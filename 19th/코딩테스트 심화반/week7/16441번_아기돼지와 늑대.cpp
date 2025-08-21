#include <iostream>
#include <vector>

using namespace std;

char map[101][101];
bool visited[101][101];

// 플러드필
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int N, M;

// 늑대가 갈 수 있는 모든 초원을 visited로 바꾸는 DFS
void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 < nr && nr <= N && 0 < nc && nc <= M) {
            // 만약 가야할 칸이 빙판일 경우 반복문 수행
            while (map[nr][nc] == '+') {
                int nnr = nr + dr[i];
                int nnc = nc + dc[i];
                if (0 < nnr && nnr <= N && 0 < nnc && nnc <= M) {
                    if (map[nnr][nnc] == '#') break; // 그 다음 칸이 산일 경우 현재 위치에서 종료
                    else { // 그 다음 칸이 산이 아닐 경우 이동
                        nr = nnr;
                        nc = nnc;
                    }
                }
                else break; // 그 다음 칸이 범위를 벗어났을 경우 종료
            }
            if (map[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 늑대들의 시작점을 저장하는 벡터
    vector<pair<int, int>> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'W') {
                v.push_back({ i, j });
            }
        }
    }
    
    int wolves_cnt = v.size();
    for (int i = 0; i < wolves_cnt; i++) {
        int sr = v[i].first;
        int sc = v[i].second;
        
        // 각 늑대별로 DFS 수행
        if (!visited[sr][sc]) {
            visited[sr][sc] = true;
            dfs(sr, sc);
        }       
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == '.' && !visited[i][j]) { // 초원이면서 방문하지 않은 점일 경우
                cout << "P";
            }
            else cout << map[i][j];
        }
        cout << "\n";
    }
}