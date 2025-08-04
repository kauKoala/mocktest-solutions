#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    int N, M;
    cin >> N >> M;

    int num;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> num;
            // (i, j)까지 올 수 있는 경로는 (i - 1, j), (i, j - 1)
            // 둘 중 사탕이 많은 것과 입력받은 사탕 개수를 더함
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + num;
        }
    }

    cout << dp[N][M];
}