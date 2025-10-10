#include <iostream>
#include <algorithm>

using namespace std;

int input[10002];
int info[11][3];

int main() {
    // 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int current_max = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input[j];
		}

		int total_sum1 = 0; // 맨 앞부터 j까지의 부분합의 최댓값을 구하기 위함
		int total_sum2 = 0; // j부터 맨 뒤까지의 부분합의 최댓값을 구하기 위함

		int inner_max = 0; // 특정 수열 내부의 부분합의 최댓값을 구하기 위함
		int current_sum = 0;

		int prefix_max = 0; // 맨 앞부터 j까지의 부분합의 최댓값
		int suffix_max = 0; // j부터 맨 뒤까지의 부분합의 최댓값
		for (int j = 1; j <= M; j++) {
			total_sum1 += input[j];
			total_sum2 += input[M - j + 1];

            // current_sum 0보다 작아지면 최대 부분합이 될 수 없음
			if (current_sum < 0) {
				current_sum = input[j];
			}
			else {
				current_sum += input[j];
			}
			inner_max = max(inner_max, current_sum);

			prefix_max = max(prefix_max, total_sum1);
			suffix_max = max(suffix_max, total_sum2);
		}

		ans = max(ans, inner_max); // 특정 수열 내부의 부분합의 최댓값이 정답인 case 처리

		if (total_sum1 > 0) current_max += total_sum1; // total_sum이 0보다 크면 수열이 중간에 들어갈 수 있음

		info[i][0] = total_sum1;
		info[i][1] = prefix_max;
		info[i][2] = suffix_max;
	}

    // brute force
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				int tmp = info[i][2] + current_max + info[j][1]; // i번 수열의 suffix + 원소의 합이 0보다 큰 모든 수열의 합 + j번 수열의 prefix
				if (info[i][0] > 0) tmp -= info[i][0]; // 만약 i번 수열의 원소의 합이 0보다 컸을 경우 tmp(current_max)에 중복으로 들어가 있기에 제거
				if (info[j][0] > 0) tmp -= info[j][0]; // 만약 i번 수열의 원소의 합이 0보다 컸을 경우 tmp(current_max)에 중복으로 들어가 있기에 제거
				
				ans = max(ans, tmp);
			}
		}
	}

	cout << ans;
}