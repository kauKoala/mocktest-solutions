#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    // 3번, 4번 연산의 경우 N과 M이 바뀌기 때문에 둘 중 큰 사이즈로 이차원 벡터 선언
    int max_size = max(N, M);
    vector<vector<int>> map(max_size, vector<int>(max_size));
    vector<vector<int>> tmp(max_size, vector<int>(max_size)); // 연산 결과를 tmp에 임시 저장

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int op;
    while (R--) {
        cin >> op;

        if (op == 1) { // 상하 반전
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    tmp[i][j] = map[N - i - 1][j];
                }
            }
            map = tmp;
        }
        if (op == 2) { // 좌우 반전
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    tmp[i][j] = map[i][M - j - 1];
                }
            }
            map = tmp;
        }
        if (op == 3) { // 오른쪽으로 90도 회전
            // N과 M을 바꿔줌
            int x = N;
            N = M;
            M = x;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    tmp[i][j] = map[M - j - 1][i]; // 밑에서 위 행으로, 왼쪽 열부터
                }
            }
            map = tmp;
        }
        if (op == 4) { // 왼쪽으로 90도 회전
            // N과 M을 바꿔줌
            int x = N;
            N = M;
            M = x;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    tmp[i][j] = map[j][N - i - 1]; // 위에서 밑 행으로, 오른쪽 열부터
                }
            }
            map = tmp;
        }
        if (op == 5) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    tmp[i][j] = map[i + N / 2][j]; // 4번 -> 1번
                }
            }
            for (int i = 0; i < N / 2; i++) {
                for (int j = M / 2; j < M; j++) {
                    tmp[i][j] = map[i][j - M / 2]; // 1번 -> 2번
                }
            }
            for (int i = N / 2; i < N; i++) {
                for (int j = 0; j < M / 2; j++) {
                    tmp[i][j] = map[i][j + M / 2]; // 3번 -> 4번
                }
            }
            for (int i = N / 2; i < N; i++) {
                for (int j = M / 2; j < M; j++) {
                    tmp[i][j] = map[i - N / 2][j]; // 2번 -> 4번
                }
            }
            map = tmp;
        }
        if (op == 6) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    tmp[i][j] = map[i][j + M / 2]; // 2번 -> 1번
                }
            }
            for (int i = 0; i < N / 2; i++) {
                for (int j = M / 2; j < M; j++) {
                    tmp[i][j] = map[i + N / 2][j]; // 3번 -> 2번
                }
            }
            for (int i = N / 2; i < N; i++) {
                for (int j = 0; j < M / 2; j++) {
                    tmp[i][j] = map[i - N / 2][j]; // 1번 -> 4번
                }
            }
            for (int i = N / 2; i < N; i++) {
                for (int j = M / 2; j < M; j++) {
                    tmp[i][j] = map[i][j - M / 2]; // 4번 -> 3번
                }
            }
            map = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}