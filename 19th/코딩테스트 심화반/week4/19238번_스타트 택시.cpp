#include <iostream>
#include <queue>

using namespace std;

int map[21][21];

// 플러드필
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

// 각 승객의 목적지
pair<int, int> end_pos[401];

int main() {
    int N, M, fuel;
    int r, c;
    int s_r, s_c, e_r, e_c;

    cin >> N >> M >> fuel;

    int input;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input;
            if (input == 1) map[i][j] = -1; // 벽을 -1로 표현
            else map[i][j] = 0;
        }
    }

    cin >> r >> c;

    for (int i = 1; i <= M; i++) {
        cin >> s_r >> s_c >> e_r >> e_c;
        map[s_r][s_c] = i; // n번 승객의 출발지를 n으로 표현 
        end_pos[i] = { e_r, e_c }; // 각 승객의 목적지가 겹칠 수 있으므로, 따로 저장
    }

    bool find_path = false;
    while (M--) {
        // 현재 위치 -> n번 승객 출발지
        // n번 승객 출발지 -> n번 승객 목적지
        // 두 번의 플러드필(BFS)
        bool visited1[21][21] = {};
        bool visited2[21][21] = {};
        queue<pair<pair<int, int>, int>> q1; // 위치(r, c)와 이동 거리 저장
        queue<pair<pair<int, int>, int>> q2; // 위치(r, c)와 이동 거리 저장
        int customer_num; // 현재 탑승중인 승객 번호

        // 첫 번째 플러드필 (현재 위치 -> n번 승객 출발지)
        find_path = false; // 승객을 찾았는지 판단하기 위함  
        int used_fuel1 = 401; // 승객을 찾는데 사용한 연료
        
        if (1 <= map[r][c]) { // 만약 현재 위치가 n번 승객의 출발지일 경우
            find_path = true;
            customer_num = map[r][c];

            used_fuel1 = 0;
        }
        else { // 빈칸이라면 플러드필 시작
            q1.push({ {r, c}, 0 });
            visited1[r][c] = true;
        }

        while (!q1.empty()) {
            auto pos = q1.front().first;
            int depth = q1.front().second;
            q1.pop();

            // 만약 연료를 다 썼거나, 다른 승객보다 멀리 위치할 경우 break
            if (fuel <= depth || depth >= used_fuel1) break; 

            // 사방으로 이동 시작
            for (int i = 0; i < 4; i++) { 
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
                    if (map[nr][nc] == -1) continue; // 벽일 경우

                    if (!visited1[nr][nc]) {
                        if (1 <= map[nr][nc]) { // n번 승객의 출발지일 경우
                            if (!find_path) { // 찾은 승객이 없을 경우
                                find_path = true;
                                customer_num = map[nr][nc];
                                r = nr;
                                c = nc;

                                used_fuel1 = depth + 1;
                            }
                            else { // 찾은 승객이 있을 경우
                                if (nr < r) { // 행 번호가 작은순
                                    customer_num = map[nr][nc];
                                    r = nr;
                                    c = nc;
                                }
                                else if (nr == r) {
                                    if (nc < c) { // 열 번호가 작은순
                                        customer_num = map[nr][nc];
                                        r = nr;
                                        c = nc;
                                    }
                                }
                            }
                        }
                        else { // 빈칸일 경우
                            q1.push({ {nr, nc}, depth + 1 });
                            visited1[nr][nc] = true;
                        }
                        
                    }
                }
            }
        }

        if (!find_path) break;
        map[r][c] = 0; // 해당 위치를 빈칸으로 만듦
        fuel -= used_fuel1;

        // 두 번째 플러드필 (n번 승객 출발지 -> n번 승객 목적지)
        find_path = false; // 승객을 도착지까지 이동시켰는지 판단하기 위함  
        int used_fuel2 = 401; // 승객을 도착지에 이동시키는데 사용한 연료

        // 플러드필 시작
        q2.push({ {r, c}, 0 });
        visited2[r][c] = true;

        while (!q2.empty()) {
            auto pos = q2.front().first;
            int depth = q2.front().second;
            q2.pop();

            // 만약 연료를 다 썼거나, 이미 경로를 찾았을 경우 break
            if (fuel <= depth || find_path) break;

            // 사방으로 이동 시작
            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
                    if (map[nr][nc] == -1) continue; // 벽일 경우

                    if (!visited2[nr][nc]) { 
                        if (nr == end_pos[customer_num].first && nc == end_pos[customer_num].second) { // 승객의 도착지일 경우
                            find_path = true;
                            r = nr;
                            c = nc;

                            used_fuel2 = depth + 1;
                        }
                        else { // 빈칸일 경우
                            q2.push({ {nr, nc}, depth + 1 });
                            visited2[nr][nc] = true;
                        } 
                    }
                }
            }
        }

        if (!find_path) break;
        fuel -= used_fuel2;

        fuel += used_fuel2 * 2;
    }

    if (!find_path) cout << -1;
    else cout << fuel;
}