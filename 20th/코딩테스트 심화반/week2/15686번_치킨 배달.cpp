#include <iostream>
#include <vector>

using namespace std;

int map[50][50];
int N, M;
int ans = 987654321;
vector<pair<int, int>> house; // 집의 좌표(x, y) 저장
vector<pair<bool, pair<int, int>>> chicken; // 치킨집의 폐업 여부, 좌표(x, y) 저장
int chicken_cnt = 0; // 초기 치킨집의 개수

// 백트래킹
void back_tracking(int idx, int chicken_idx) {
    // 도시의 치킨 거리 계산 로직
	int dist_sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = 987654321;
		for (int j = 0; j < chicken.size(); j++) {
            // 치킨집이 폐업하지 않은 경우
			if (chicken[j].first) {
                // 치킨집의 x, y좌표 - 집의 x, y좌표의 절댓값
				dist = min(dist, abs(chicken[j].second.first - house[i].first) + abs(chicken[j].second.second - house[i].second));
			}
		}
		dist_sum += dist;
	}

    // 시간복잡도를 위한 pruning
	if (chicken_cnt - idx <= M || dist_sum >= ans) {
		ans = min(ans, dist_sum);
		return;
	}

    // brute force
	for (int i = chicken_idx; i < chicken.size(); i++) {
        // 치킨집이 폐업하지 않은 경우
		if (chicken[i].first) {
			chicken[i].first = false; // i번 치킨집 폐업

			back_tracking(idx + 1, i + 1);

			chicken[i].first = true; // i번 치킨집 폐업 취소
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) house.push_back({ i, j });
			if (map[i][j] == 2) {
				chicken_cnt++;
				chicken.push_back({ true, { i, j } });
			}
		}
	}

	back_tracking(0, 0);

	cout << ans;
}