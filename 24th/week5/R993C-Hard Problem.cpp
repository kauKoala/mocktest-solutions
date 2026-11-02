#include <iostream>
#include <algorithm>

using namespace std;

// 자리가 m개씩 있는 두 줄에, 원숭이를 최대한 많이 앉히는 문제

// a마리는 1열에만, b마리는 2열에만 앉을 수 있고, c마리는 아무 열이나 앉을 수 있다.
// 선호가 있는 a, b 원숭이를 먼저 자기 열에 최대한(최대 m마리) 앉히고,
// 선호가 없는 c 원숭이는 두 열에 남은 자리에 앉힌다.

// a, b를 먼저 앉히는 이유:
// c를 먼저 앉히면 a, b만 앉을 수 있는 자리를 차지해 버릴 수 있지만,
// a, b를 먼저 앉혀도 c는 남은 어느 자리에나 앉을 수 있으므로 손해가 없다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 한 줄의 자리 수, 1열 선호, 2열 선호, 선호 없음 원숭이 수 입력 처리
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        // 변수 선언
        int row1 = min(a, m);                  // 1열에 앉은 a 원숭이 수 (자리는 최대 m개)
        int row2 = min(b, m);                  // 2열에 앉은 b 원숭이 수 (자리는 최대 m개)
        int remain_seat = 2 * m - row1 - row2; // 두 열을 합쳐 남은 자리 수

        // 선호가 없는 c 원숭이는 남은 자리만큼만 앉을 수 있음
        int answer = row1 + row2 + min(c, remain_seat);

        // 출력 처리
        cout << answer << "\n";
    }

    return 0;
}
