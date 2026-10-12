#include <iostream>

using namespace std;

// 좌표에서 일정 이상 연속된 빈 지점이 있는지 구하는 유형이다.
// 배열로 접근하면 m이 10억이기 때문에 메모리가 부족해진다.
// 문제에서 일정은 시간순으로 주어진다는 조건이 있으므로, 입력과 동시에 계산하는 방식으로 구현한다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 일정 개수, 샤워 시간, 하루 시간 입력 처리
        int n, s, m;
        cin >> n >> s >> m;

        // 변수 선언
        int shower_start = 0;
        bool success = false;

        // n개 일정 입력 처리
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;

            // 일정의 시작 바로 전에 비어 있는 총 시간 계산
            int emtpy_time = l - shower_start;

            // 비어 있는 시간이 샤워 시간보다 길거나 같다면,
            if (emtpy_time >= s) {
                success = true;      // 샤워 가능 처리
            }

            // 샤워 시작 시간 갱신
            // 다음으로 샤워 시작이 가능한 시간은 일정의 종료 지점
            shower_start = r;
        }

        // 모든 일정이 끝난 지점 계산
        if (m - shower_start >= s) {
            success = true;
        }

        // 출력 처리
        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
