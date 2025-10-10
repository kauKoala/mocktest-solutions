#include <iostream>

using namespace std;

// H x N
// 가로선의 시작 좌표 저장
bool board[31][11];

int N, M, H;
int ans = 4;

// 백트래킹
void back_tracking(int idx, int r, int c) {
	// 사다리 타기를 수행했을 때 문제의 조건에 맞는지 확인하는 로직
	bool possible = true;
	for (int start = 1; start <= N; start++) {
		// 현재 위치, 초깃값은 시작점
		int pos = start; 
		for (int i = 1; i <= H; i++) {
			// 가로선의 시작점을 만났을 경우
			if (board[i][pos]) pos++; 
			// 가로선의 끝점을 만났을 경우
			else if (board[i][pos - 1]) pos--;
		}
		if (pos != start) {
			possible = false;
			break;
		}
	}

	if (possible) {
		ans = min(ans, idx);
		return;
	}

	// 시간복잡도를 위한 pruning
	if (idx == 3 || idx >= ans) return;

	// brute force
	for (int i = r; i <= H; i++) {
		int k = 1;
		if (i == r) k = c; // 이전까지 탐색했던 좌표 이후부터 시작, 조합
		for (int j = k; j < N; j++) {
			// 양쪽에 사다리가 존재하지 않을 경우
			if (!board[i][j] && !board[i][j + 1] && !board[i][j - 1]) {
				board[i][j] = true; // 사다리 설치
				back_tracking(idx + 1, i, j);
				board[i][j] = false; // 사다리 해체
			}
		}
	}
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
	}

	back_tracking(0, 1, 1);

	if (ans < 4) cout << ans;
	else cout << -1;	
}