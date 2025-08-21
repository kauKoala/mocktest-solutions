#include <iostream>

using namespace std;

int map[128][128];

int white_cnt = 0; // 하얀색 색종이 개수
int blue_cnt = 0; // 파란색 색종이 개수

// 재귀 함수
// 현재 탐색해야 할 색종이 영역에 대해서 탐색
// 색이 공존할 경우 재귀 수행
// 단일 색만 존재하면 재귀 멈춤
void find_ans(int N, int r, int c) { // 현재 한 변의 길이, 나누어진 색종이의 왼쪽 상단 좌표
    int find_white = false; // 하얀색 색종이가 존재하는지
    int find_blue = false; // 파란색 색종이가 존재하는지

    // 나누어진 색종이 전체를 탐색
    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++) {
            if (map[i][j] == 0) find_white = true; // 하얀색 색종이를 찾았을 경우
            else find_blue = true; // 파란색 색종이를 찾았을 경우
        }
    }

    if (find_white && find_blue) { // 하얀색, 파란색 색종이가 모두 존재할 경우 네 등분
        find_ans(N / 2, r, c); // 왼쪽 상단
        find_ans(N / 2, r + N / 2, c); // 왼쪽 하단
        find_ans(N / 2, r, c + N / 2); // 오른쪽 상단
        find_ans(N / 2, r + N / 2, c + N / 2); // 오른쪽 하단
    }
    else { // 둘 중 하나의 색종이만 존재할 경우
        if (find_white) white_cnt++; // 하얀색 색종이의 개수 늘림
        else blue_cnt++; // 파란색 색종이의 개수 늘림
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    find_ans(N, 0, 0);

    cout << white_cnt << "\n";
    cout << blue_cnt << "\n";
}