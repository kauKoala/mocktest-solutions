#include <iostream>
#include <stack>

using namespace std;

int map[128][128];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // stack에 색종이의 size와 색종이의 시작점(r, c) 저장
    stack<pair<int, pair<int, int>>> s;

    int white_cnt = 0; // 하얀색 색종이 개수
    int blue_cnt = 0; // 파란색 색종이 개수

    s.push({ N, {0, 0} }); // 제일 큰 size의 종이부터 시작
    while (!s.empty()) {
        int size = s.top().first; // 색종이의 size
        int r = s.top().second.first; // 색종이의 시작 행
        int c = s.top().second.second; // 색종이의 시작 열
        s.pop();

        int find_white = false; // 하얀색 발견 여부
        int find_blue = false; // 파란색 발견 여부

        // 시작점부터 size크기만큼의 영역 탐색
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (map[i][j] == 0) find_white = true; // 하얀색 발견 
                else find_blue = true; // 파란색 발견 
            }
        }

        // 하얀색과 파란색을 모두 발견했을 경우
        if (find_white && find_blue) {
            s.push({ size / 2, { r, c } }); // 사이즈를 줄이고, 시작점을 그대로 다시 탐색
            s.push({ size / 2, { r + size / 2, c } }); // 사이즈를 줄이고, 시작 행에 size를 더하여 다시 탐색
            s.push({ size / 2, { r, c + size / 2 } }); // 사이즈를 줄이고, 시작 열에 size를 더하여 다시 탐색
            s.push({ size / 2, { r + size / 2, c + size / 2 } }); // 사이즈를 줄이고, 시작 행, 열에 size를 더하여 다시 탐색
        }
        // 하얀색만 발견했을 경우
        else if (find_white) {
            white_cnt++; // 하얀색 색종이 개수 증가
        }
        else {
            blue_cnt++; // 파란색 색종이 개수 증가
        }
    }

    cout << white_cnt << "\n";
    cout << blue_cnt << "\n";
}