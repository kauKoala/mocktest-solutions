#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[50][50];

int N;
int ans = 0;

// 현재 보드를 기준으로 먹을 수 있는 최대 사탕 개수를 구하는 함수
void find_max_value() {
	for (int i = 0; i < N; i++) {
		int ccnt1 = 0, pcnt1 = 0, zcnt1 = 0, ycnt1 = 0;
		int ccnt2 = 0, pcnt2 = 0, zcnt2 = 0, ycnt2 = 0;
		for (int j = 0; j < N; j++) {
			// 열 기준
			if (board[i][j] == 'C') {
				ccnt1++;
				pcnt1 = 0;
				zcnt1 = 0;
				ycnt1 = 0;
			}
			if (board[i][j] == 'P') {
				ccnt1 = 0;
				pcnt1++;
				zcnt1 = 0;
				ycnt1 = 0;
			}
			if (board[i][j] == 'Z') {
				ccnt1 = 0;
				pcnt1 = 0;
				zcnt1++;
				ycnt1 = 0;
			}
			if (board[i][j] == 'Y') {
				ccnt1 = 0;
				pcnt1 = 0;
				zcnt1 = 0;
				ycnt1++;
			}

			// 행 기준
			if (board[j][i] == 'C') {
				ccnt2++;
				pcnt2 = 0;
				zcnt2 = 0;
				ycnt2 = 0;
			}
			if (board[j][i] == 'P') {
				ccnt2 = 0;
				pcnt2++;
				zcnt2 = 0;
				ycnt2 = 0;
			}
			if (board[j][i] == 'Z') {
				ccnt2 = 0;
				pcnt2 = 0;
				zcnt2++;
				ycnt2 = 0;
			}
			if (board[j][i] == 'Y') {
				ccnt2 = 0;
				pcnt2 = 0;
				zcnt2 = 0;
				ycnt2++;
			}

			ans = max({ ans, ccnt1, pcnt1, zcnt1, ycnt1, ccnt2, pcnt2, zcnt2, ycnt2 });
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	find_max_value();

	// brute force
	char a, b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 행 교체
			if (i < N - 1) {
				a = board[i][j];
				b = board[i + 1][j];

				// 인접한 사탕 교체
				board[i][j] = b;
				board[i + 1][j] = a;

				find_max_value();

				// 되돌림
				board[i][j] = a;
				board[i + 1][j] = b;
			}

			// 열 교체
			if (j < N - 1) {
				a = board[i][j];
				b = board[i][j + 1];

				// 인접한 사탕 교체
				board[i][j] = b;
				board[i][j + 1] = a;

				find_max_value();

				// 되돌림
				board[i][j] = a;
				board[i][j + 1] = b;
			}
			
		}
	}

	cout << ans;
}