#include <iostream>

using namespace std;

int dp[31];

int main() {
    int D, K;
    cin >> D >> K;

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 30; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // 피보나치 수열 저장
    }

    // D = 1 : A
    // D = 2 : B
    // D = 3 : A + B
    // D = 4 : A + B + B
    // D = 5 : A + A + B + B + B
    // D가 3일 경우 A는 dp[0], B는 dp[1]
    // D가 4일 경우 A는 dp[1], B는 dp[2]
    // D가 5일 경우 A는 dp[2], B는 dp[3]
    int pibo1 = dp[D - 3];
    int pibo2 = dp[D - 2];

    // 투포인터로 값 찾기
    // i는 1, j는 최댓값이 K를 pibo2로 나눈 몫 + 나머지
    int i = 1, j = K / pibo2 + K % pibo2; 
    while (i <= j) {
        if (i * pibo1 + j * pibo2 < K) i++;
        else if (i * pibo1 + j * pibo2 > K) j--;
        else break;
    }

    cout << i << "\n";
    cout << j;
}