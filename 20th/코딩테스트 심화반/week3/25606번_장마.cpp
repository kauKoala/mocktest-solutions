#include <iostream>

using namespace std;

int ans[2][100001]; // 모든 상자에 들어있는 물의 양의 합 & 모든 상자에서 증발하는 물의 양의 합
int minus_cnt[100001]; // 남은 물이 모두 증발하게 되는 상자의 개수

int main() {
    // 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, Q;
	cin >> N >> M >> Q;

	int cnt = 0; // 증발해야 할 상자의 개수
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;

        // 현재 상자의 물이 증발하게 되는 시점
		int next_idx = a / M + 1 + i;
		if (a % M == 0) next_idx--;

		if (next_idx <= N) {
			minus_cnt[next_idx]++;

            // cnt(증발해야 할 상자의 개수) * M 만큼을 뺄 예정이기에 M에서 a를 뺀 나머지를 미리 더해놓음
			ans[0][next_idx] += (M - (a % M)) % M;
            // cnt(증발해야 할 상자의 개수) * M 만큼을 더할 예정이기에 M에서 a를 뺀 나머지를 미리 빼놓음
			ans[1][next_idx] -= (M - (a % M)) % M;
		}

        // 내린 비의 양 + 어제까지의 물의 총량 - 증발량
		ans[0][i] += a + ans[0][i - 1] - cnt * M;
        // 증발량
		ans[1][i] += cnt * M;

		cnt -= minus_cnt[i]; // 남은 물이 모두 증발한 상자 제거
		cnt++;
	}

	for (int i = 0; i < Q; i++) {
		int c, t;
		cin >> c >> t;

		cout << ans[c - 1][t] << "\n";
	}
}