#include <iostream>
#include <vector>

using namespace std;

// 1 이상 n 이하의 수로 배열 b를 만들어,
// 모든 i에 대해 a[i]가 b[1..i]의 최빈값이 되도록 하는 문제

// b의 원소를 모두 서로 다르게 만들면, 어느 앞부분 b[1..i]를 보더라도
// 들어 있는 수들의 등장 횟수가 전부 1로 같으므로, 들어 있는 모든 수가 최빈값이 된다.
// 따라서 a[i]가 b[1..i] 안에 한 번이라도 들어 있기만 하면 조건을 만족한다.

// i를 앞에서부터 보면서
// - a[i]가 아직 b에 없으면, b[i]에 a[i]를 넣는다.
// - a[i]가 이미 b에 있으면, 아직 b에 쓰지 않은 아무 수를 b[i]에 넣는다.
// 두 경우 모두 b에 한 번도 쓰지 않은 수를 넣으므로 b의 원소는 서로 다르고 (1~n의 순열),
// a[i]는 항상 b[1..i] 안에 들어 있게 된다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 배열 길이 n, 배열 a 입력 처리
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 변수 선언
        vector<int> b(n);                 // 정답 배열
        vector<bool> used(n + 1, false);  // 수 x가 이미 b에 들어갔는지 저장 (1~n 사용)
        int next_num = 1;                 // 아직 b에 쓰지 않은 수를 찾기 위한 포인터

        for (int i = 0; i < n; i++) {
            // a[i]가 아직 b에 없다면, 그대로 b[i]에 넣기
            if (!used[a[i]]) {
                b[i] = a[i];
                used[a[i]] = true;
            }
            // a[i]가 이미 b에 있다면, 아직 쓰지 않은 수를 찾아 b[i]에 넣기
            else {
                while (used[next_num]) {
                    next_num++;   // 이미 쓴 수는 건너뜀
                }
                b[i] = next_num;
                used[next_num] = true;
            }
        }

        // 출력 처리 (공백으로 구분)
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
