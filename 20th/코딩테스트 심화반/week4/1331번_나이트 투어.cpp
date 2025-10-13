#include <iostream>

using namespace std;

bool visited[6][6];

int main() {
	char c;
	int r;
	bool possible = true;
	int first_x, first_y; // 시작 위치 저장
	int last_x, last_y; // 마지막 위치 저장
	for (int i = 0; i < 36; i++) {
		cin >> c >> r;
		int x = r - 1; 
		int y = c - 'A';
		if (visited[x][y]) {
			possible = false;
		}
		else {
			visited[x][y] = true;
			if (i != 0) {
				// 마지막 위치와 현재 위치가 나이트의 이동 경로인지 확인
				if (!((abs(last_x - x) == 2 && abs(last_y - y) == 1) || (abs(last_x - x) == 1 && abs(last_y - y) == 2))) { 
					possible = false;
				}
			}
			else {
				// 시작 위치 저장ㄴ
				first_x = x;
				first_y = y;
			}
		}
		last_x = x;
		last_y = y;
	}

	// 마지막 위치와 시작 위치가 나이트의 이동 경로인지 확인
	if (!((abs(last_x - first_x) == 2 && abs(last_y - first_y) == 1) || (abs(last_x - first_x) == 1 && abs(last_y - first_y) == 2))) {
		possible = false;
	}
	
	if (possible) cout << "Valid";
	else cout << "Invalid";
}