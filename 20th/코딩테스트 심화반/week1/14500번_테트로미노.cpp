#include <iostream>

using namespace std;

int paper[500][500];

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	int ans = 0;
	int tmp;
	// 각 점(i, j)에서 시작하여 오른쪽 or 아래로만 향하도록 테트로미노를 배치
	// 중복으로 테트로미노가 배치되는 것을 피하기 위함
	// 종이의 크기를 벗어나지 않도록 조건 설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 1번 하늘색 테트로미노
			if (i < N - 3) {
				tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
				ans = max(ans, tmp);
			}
			if (j < M - 3) {
				tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
				ans = max(ans, tmp);
			}

			// 2번 노란색 테트로미노
			if (i < N - 1 && j < M - 1) {
				tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1];
				ans = max(ans, tmp);
			}

			// 3번 주황색 테트로미노
			if(i < N - 2) {
				if (j < M - 1) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
					ans = max(ans, tmp);

					tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
					ans = max(ans, tmp);
				}
				if (0 < j) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j - 1];
					ans = max(ans, tmp);

					tmp = paper[i][j] + paper[i][j - 1] + paper[i + 1][j - 1] + paper[i + 2][j - 1];
					ans = max(ans, tmp);
				}
			}
			if (j < M - 2) {
				if (i < N - 1) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2];
					ans = max(ans, tmp);

					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
					ans = max(ans, tmp);
				}
				if (0 < i) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 2];
					ans = max(ans, tmp);

					tmp = paper[i][j] + paper[i - 1][j] + paper[i - 1][j + 1] + paper[i - 1][j + 2];
					ans = max(ans, tmp);
				}
			}

			// 4번 연두색 테트로미노
			if (i < N - 2) {
				if (j < M - 1) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
					ans = max(ans, tmp);
				}
				if (0 < j) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j - 1] + paper[i + 2][j - 1];
					ans = max(ans, tmp);
				}
			}
			if (j < M - 2) {
				if (i < N - 1) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
					ans = max(ans, tmp);
				}
				if (0 < i) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i - 1][j + 1] + paper[i - 1][j + 2];
					ans = max(ans, tmp);
				}
			}

			// 5번 분홍색 테트로미노
			if (i < N - 2) {
				if (j < M - 1) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1];
					ans = max(ans, tmp);
				}
				if (0 < j) {
					tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j - 1];
					ans = max(ans, tmp);
				}
			}
			if (j < M - 2) {
				if (i < N - 1) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1];
					ans = max(ans, tmp);
				}
				if (0 < i) {
					tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 1];
					ans = max(ans, tmp);
				}
			}
		}
	}
	cout << ans;
}