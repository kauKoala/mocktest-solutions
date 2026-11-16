#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1부터 n까지의 각 수 i에 대해, 배열의 원소를 최소 몇 개 곱해야
// 곱이 정확히 i가 되는지 구하는 문제이다.

// dp[i] = 곱이 i가 되도록 고르는 원소의 최소 개수라 하고,
// 배열에 들어 있는 값 v는 그 원소 하나만 고르면 되므로 dp[v] = 1 이다.

// 곱이 i인 상태에서 배열의 값 d를 하나 더 곱하면 곱이 i*d가 된다.
// 값 1은 곱해도 수가 변하지 않고 개수만 늘어나므로 곱하는 수 d에서 제외한다.
// 그러면 i*d는 항상 i보다 크므로, i를 1부터 오름차순으로 처리하면,
// i를 볼 때 dp[i]는 이미 확정된 값이다.

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        // 배열에 있는 값은 원소 하나로 만들 수 있다.
        vector<int> dp(n + 1, INF);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            dp[a] = 1;
        }

        // 곱하는 수로 쓸 값들을 중복 없이 오름차순으로 정리
        vector<int> mults;
        for (int v = 2; v <= n; v++) {
            if (dp[v] == 1) {
                mults.push_back(v);
            }
        }

        // 작은 수부터 차례대로, 배열의 값을 하나 더 곱해 보기
        for (int i = 1; i <= n; i++) {
            // 만들 수 없는 수에서는 더 뻗어 나갈 수 없다.
            if (dp[i] == INF) {
                continue;
            }

            for (int d : mults) {
                long long nxt = (long long)i * d;

                // n을 넘으면 더 큰 d는 볼 필요가 없다.
                if (nxt > n) {
                    break;
                }

                dp[nxt] = min(dp[nxt], dp[i] + 1);
            }
        }

        // 출력 처리 (만들 수 없는 수는 -1로 바꿔서 출력)
        for (int i = 1; i <= n; i++) {
            cout << (dp[i] == INF ? -1 : dp[i]) << " ";
        }
        cout << "\n";
    }

    return 0;
}