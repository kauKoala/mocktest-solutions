#include <iostream>

using namespace std;

// 입력받은 n의 각 자리 숫자의 합을 구하는 문제
// 십의 자리 수는 몫 연산으로, 일의 자리 수는 나눗셈 연산으로 구할 수 있다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // n 입력 처리
        int n;
        cin >> n;

        // 십의 자리 수와 일의 자리 수 더한 후, 출력
        cout << n / 10 + n % 10 << "\n";
    }

    return 0;
}
