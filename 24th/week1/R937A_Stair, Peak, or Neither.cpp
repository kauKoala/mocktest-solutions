#include <iostream>

using namespace std;

int main() {
    // 주어진 3개 숫자(a, b, c)가 어떤 모양인지 판단하는 문제

    // 입력 처리
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // 점차 증가하는 계단 모양인 경우 조건 처리
        if (a < b && b < c) {
            cout << "STAIR\n";
        }
        // 가운데 숫자가 가장 큰 봉우리 모양인 경우 조건 처리
        else if (a < b && b > c) {
            cout << "PEAK\n";
        }
        // 둘 다 아닐 때
        else {
            cout << "NONE\n";
        }
    }

    return 0;
}