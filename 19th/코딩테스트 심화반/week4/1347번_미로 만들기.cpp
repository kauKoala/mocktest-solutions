#include <iostream>
#include <string>
    
using namespace std;
    
bool visited[101][101]; // 상하좌우로 최대 50만큼 이동할 수 있기에 100 by 100으로 설정 
    
int main() {
    int N;
    cin >> N;

    string str;
    cin >> str;

    int r = N, c = N; // 이차원 배열의 범위를 벗어나지 않도록 (N, N)에서 시작
    visited[N][N] = true;

    int min_r = r, max_r = r; // 이동한 범위만큼만 출력하기 위함
    int min_c = c, max_c = c; // 이동한 범위만큼만 출력하기 위함

    int direct = 0; // 현재 바라보고 있는 방향(남쪽 - 0, 서쪽 - 1, 북쪽 - 2, 동쪽 - 4)

    // 바라보는 방향에 맞게 이동할 수 있도록 설정
    int dr[4] = { 1, 0, -1, 0 };
    int dc[4] = { 0, -1, 0, 1 };  

    for (int i = 0; i < N; i++) {
        if (str[i] == 'R') {
            direct = (direct + 1) % 4;
        }
        if (str[i] == 'L') {
            direct = (direct + 3) % 4;
        }
        if (str[i] == 'F') {
            r += dr[direct];
            c += dc[direct];

            visited[r][c] = true;

            min_r = min(min_r, r);
            max_r = max(max_r, r);
            min_c = min(min_c, c);
            max_c = max(max_c, c);
        }
    }

    for (int i = min_r; i <= max_r; i++) {
        for (int j = min_c; j <= max_c; j++) {
            if (visited[i][j]) cout << "."; // 만약 방문했다면 . 출력
            else cout << "#"; // 아니라면 # 출력
        }
        cout << "\n";
    }
}