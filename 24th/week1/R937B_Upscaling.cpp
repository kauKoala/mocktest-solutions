#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입력 n값에 따라 격자를 출력하는 문제

    // 격자 2n*2n을 탐색하며 출력해도 좋지만,
    // 이번에는 행(가로)으로 나누어 풀이한다.

    // 입력 처리
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // 짝수행 문자열 구하기
        string even = "";
        for (int col = 0; col < n; col++) {
            if (col % 2) {
                even = even + "..";
            } else {   // 짝수행은 ##으로 시작
                even = even + "##";
            }
        }

        // 홀수행 문자열 구하기
        string odd = ".." + even.substr(0, even.length() - 2);

        // 0~n-1 행까지 격자를 출력
        for (int row = 0; row < n; row++) {
            if (row % 2) {     // 홀수행
                cout << odd << "\n" << odd << "\n";
            } else {           // 짝수행
                cout << even << "\n" << even << "\n";
            }
        }
    }

    return 0;
}