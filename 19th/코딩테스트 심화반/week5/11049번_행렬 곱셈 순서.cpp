#include <iostream>

using namespace std;

int dp[501][501];
pair<int, int> matrix[501];

int main() {
    int N;
    cin >> N;

    int r, c;
    for (int i = 1; i <= N; i++) {
        cin >> r >> c;
        matrix[i] = { r, c };
    }

    // 알고리즘 해석 및 설계 과목 동적 계획법 강의 자료 참고
    // (start, end)의 행렬 곱셈 연산 횟수의 최솟값을 dp[start][end]에 저장
    // 가까운 행렬 곱부터 시작 ex) (1, 2), (2, 3) .... (N - 1, N)
    // 한 칸씩 늘려가며 최솟값을 구함 ex) (1, 3) => (1, 2) * 3 or 1 * (2, 3)
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N - i; j++) {
            int start = j;
            int end = i + j;

            // start와 end 사이에 k라는 중간 점을 두어 (start, k) * (k + 1, end)의 최솟값을 구함
            int min_value = 1234567890;
            for (int k = start; k < end; k++) { 
                min_value = min(min_value, dp[start][k] + dp[k + 1][end] + matrix[start].first * matrix[k].second * matrix[end].second);
            }
            dp[start][end] = min_value;
        }
    }

    cout << dp[1][N]; 
}