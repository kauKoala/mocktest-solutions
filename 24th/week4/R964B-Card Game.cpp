#include <iostream>

using namespace std;

// 경기가 이루어질 경우의 수는 총 4가지 뿐이므로,
// 조건 처리를 이용해 해결한다.
// 이길 조건은 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=)한다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        // 정답을 저장할 변수 선언
        int answer = 0;

        // a1 vs b1, a2 vs b2
        // 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=) 최종 승리
        if ((a1 > b1 && a2 >= b2) || (a1 >= b1 && a2 > b2)) {
            answer += 2;
        }

        // a1 vs b2, a2 vs b1
        // 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=) 최종 승리
        if ((a1 > b2 && a2 >= b1) || (a1 >= b2 && a2 > b1)) {
            answer += 2;
        }

        // 출력 처리
        cout << answer << "\n";
    }

    return 0;
}
