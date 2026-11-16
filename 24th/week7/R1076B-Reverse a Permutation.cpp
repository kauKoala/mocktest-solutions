#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 순열에서 구간 [l, r]을 정확히 한 번 뒤집어, 사전순으로 가장 큰 순열을 만드는 문제이다.

// 사전순으로 가장 크려면 앞자리부터 최대한 큰 수가 와야 한다.
// => 가장 이상적인 모양은 n, n-1, n-2, ..., 1 이다.

// 앞에서부터 보면서 이상적인 값이 이미 놓여 있는 자리는 건드리지 않는다.
// 건드리면 그 자리의 값이 작아져서 무조건 손해이다.

// 모든 자리가 이미 내림차순으로 이상적이라면, l=r로 골라 아무것도 바꾸지 않으면 된다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        // 이상적인 값이 놓여 있지 않은 첫 번째 자리 찾기
        int i = 0;
        while (i < n && p[i] == n - i) {
            i++;
        }

        // 그런 자리가 있다면, 값 n-i가 있는 위치 j를 찾아 구간 뒤집기
        if (i < n) {
            int j = i;
            while (p[j] != n - i) {
                j++;
            }
            reverse(p.begin() + i, p.begin() + j + 1);
        }

        // 출력 처리
        for (int k = 0; k < n; k++) {
            cout << p[k] << " ";
        }
        cout << "\n";
    }

    return 0;
}