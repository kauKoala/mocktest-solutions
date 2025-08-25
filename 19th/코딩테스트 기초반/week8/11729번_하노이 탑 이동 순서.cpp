#include <iostream>
#include <cmath>

using namespace std;

// 하노이 탑 이동을 출력하는 재귀 함수
// N : 옮겨야 하는 원판의 개수
// a : 시작 기둥
// b : 보조 기둥
// c : 목표 기둥
void hanoi(int N, int a, int b, int c) {
    if (N == 1) {
        cout << a << " " << c << "\n"; // 원판이 1개일 경우 a에서 c로 이동
    }
    else {
        // 1. N - 1개의 원판을 a에서 b로 이동
        hanoi(N - 1, a, c, b);
        // 2. 현재 가장 큰 원판을 a에서 c로 이동
        cout << a << " " << c << "\n";
        // 3. N - 1개의 원판을 b에서 c로 이동
        hanoi(N - 1, b, a, c);
    }
}

int main() {
    int N;
    cin >> N; 

    // 하노이 탑의 최소 이동 횟수 = 2^N - 1
    // 1. N - 1개의 원판을 보조 기둥으로 옮김
    // 2. 가장 큰 원판을 목표 기둥으로 옮김
    // 3. 다시 N - 1개의 원판을 목표 기둥으로 옮김
    // 점화식: T(N) = 2 * T(N - 1) + 1
    // T(1) = 1, T(2) = 3, T(3) = 7 ...
    cout << int(pow(2, N)) - 1 << "\n";

    hanoi(N, 1, 2, 3);
}