#include <iostream>
#include <algorithm>

using namespace std;

// 두 정수 x, y를 작은 수, 큰 수 순서로 출력하는 문제

// 두 수 중 작은 값은 min, 큰 값은 max로 구할 수 있다.
// min(x, y)를 먼저, max(x, y)를 나중에 출력한다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 두 정수 입력 처리
        int x, y;
        cin >> x >> y;

        // 작은 수, 큰 수 순서로 출력
        cout << min(x, y) << " " << max(x, y) << "\n";
    }

    return 0;
}
