#include <iostream>

using namespace std;

// 배열의 원소 하나를 골라 x를 더하는 연산을 원하는 만큼 반복해서
// 배열의 합을 정확히 s로 만들 수 있는지 판별하는 문제이다.

// 어떤 원소를 고르든 연산 한 번에 배열의 합은 항상 x만큼 커진다.
// 어느 인덱스를 고르는지는 중요하지 않고 '연산을 몇 번 하는지'만 중요하다.
// 연산을 k번 하면 배열의 합은 "처음 합 + k*x" 가 된다.

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, s, x;
        cin >> n >> s >> x;

        // 처음 배열의 합
        int total = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            total += a;
        }

        // 합이 s이하이고, 부족한 양이 x의 배수인지 확인
        if (total <= s && (s - total) % x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}