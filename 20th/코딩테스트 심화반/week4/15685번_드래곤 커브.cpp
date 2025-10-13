#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

int main() {
	// d = 0일 경우 x 증가, d = 1일 경우 y 감소, d = 2일 경우 x 감소, d = 3일 경우 y 증가
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<pair<int, int>> v;
		v.push_back({ x, y });
		v.push_back({ x + dx[d], y + dy[d] });

		// 시뮬레이션
		// 드래곤 커브 생성
		for (int i = 0; i < g; i++) {
			int size = v.size();
			int last_x = v[size - 1].first;
			int last_y = v[size - 1].second;

			// 시계방향으로 90도를 꺾음
			// 끝 점과 특정 점의 y차이를 끝 점의 x좌표에서 뺌
			// 끝 점과 특정 점의 x차이를 끝 점의 y좌표에 더함
			// 이유:
			// x방향으로 증가하는 직선을 시계방향으로 90도를 꺾으면 y방향으로 증가하는 직선이 됨
			// y방향으로 증가하는 직선을 시계방향으로 90도를 꺾으면 x방향으로 감소하는 직선이 됨
			// 따라서 y축과 평행한 선분을 시계방향으로 90도 꺾는 경우 x좌표에 더할 때 - 처리를 해줌
			for (int j = size - 2; j >= 0; j--) {
				int n_x = last_x - (v[j].second - last_y);
				int n_y = last_y + (v[j].first - last_x);

				v.push_back({ n_x, n_y });
			}
		}

		for (int i = 0; i < v.size(); i++) {
			// y좌표는 행렬에서 row, x좌표는 행렬에서 column에 해당
			map[v[i].second][v[i].first]++;
		}
	}

	

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] > 0 && map[i][j + 1] > 0 && map[i + 1][j] > 0 && map[i + 1][j + 1] > 0) {
				ans++;
			}
		}
	}

	cout << ans;
}