#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> v; // 빈 칸의 좌표(x, y) 저장

// 백트래킹
bool back_tracking(int idx) {
	if (v.size() == idx) return true; // 마지막까지 빈 칸을 채웠을 경우 true 반환

	int i = v[idx].first;
	int j = v[idx].second;
	int area_i = i / 3 * 3; // 9개의 3 by 3 정사각형 중 행의 위치
	int area_j = j / 3 * 3; // 9개의 3 by 3 정사각형 중 열의 위치
	for (int num = 1; num <= 9; num++) {
		bool possible = true;
		// 가로 or 세로에 num이 존재할 경우 불가능
		for (int k = 1; k <= 9; k++) {
			if (board[(i + k) % 9][j] == num) possible = false;
			if (board[i][(j + k) % 9] == num) possible = false;
		}
		// 3 by 3 정사각형 내에 num이 존재할 경우 불가능
		for (int r = area_i; r < area_i + 3; r++) {
			for (int c = area_j; c < area_j + 3; c++) {
				if (board[r][c] == num) possible = false;
			}
		}

		if (possible) {
			board[i][j] = num; // 보드에 num을 넣음
			if (back_tracking(idx + 1)) return true;
			board[i][j] = 0; // 해당 num을 넣어서 실패했을 경우 다시 0으로 초기화
		}
	}
	
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				v.push_back({ i, j });
			}
		}
	}

	// 스도쿠를 해결했을 경우
	if (back_tracking(0)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
}