#include <iostream>

using namespace std;

// 세 정수 a, b, c 중 하나가 나머지 두 수의 합인지 판별하는 문제

// "하나가 나머지 두 수의 합"이 되는 경우는 다음 3가지뿐이다.
// a + b == c, a + c == b, b + c == a
// 셋 중 하나라도 만족하면 YES, 아니면 NO를 출력한다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 세 정수 입력 처리
        int a, b, c;
        cin >> a >> b >> c;

        // 3가지 경우 중 하나라도 만족하는지 확인 후 출력
        if (a + b == c || a + c == b || b + c == a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
