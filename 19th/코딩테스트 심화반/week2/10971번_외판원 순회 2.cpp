#include <iostream>

using namespace std;

int map[11][11];

int N;
int ans = 1234567890;
bool visited[11];

// 현재 위치, 현재까지의 비용, 현재 이동 횟수
void back_tracking(int current_city, int current_sum, int step) {
    // 1로 가는 비용 추가
    if (step == N - 1) {
        if (map[current_city][1] == 0) return; // 만약 0이면 갈 수 없음
        ans = min(ans, current_sum + map[current_city][1]); // 최소 여행 경로 갱신
        return;
    }
    // 다음 경로 탐색
    for (int i = 1; i <= N; i++) {
        // 이미 방문했거나, 다음 방문할 점이 갈 수 없을 경우 continue
        if (visited[i] || map[current_city][i] == 0) continue;
        visited[i] = true; // 방문한 점을 저장
        // 현재 위치, 현재까지의 비용, 현재 이동 횟수 갱신
        back_tracking(i, current_sum + map[current_city][i], step + 1);
        visited[i] = false; // 초기화
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    // 무조건 1에서 시작
    visited[1] = true;

    // 경로 탐색
    for (int i = 1; i <= N; i++) {
        if (map[1][i] == 0) continue; // 0이면 길이 없는 것
        visited[i] = true; // 방문한 점 저장
        back_tracking(i, map[1][i], 1);
        visited[i] = false; // 초기화
    }

    cout << ans;
}