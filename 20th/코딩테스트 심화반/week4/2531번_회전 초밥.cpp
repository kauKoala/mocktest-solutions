#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	
	vector<int> v(N);
	vector<int> cnt(d + 1, 0); // 연속된 k개의 접시 중 각 초밥의 종류가 나온 횟수

	cnt[c]++; // 쿠폰의 초밥은 무조건 먹음
	int eat_cnt = 1; // 현재 먹은 초밥의 가짓수
	for (int i = 0; i < N; i++) {
		cin >> v[i];

        // 0번부터 k - 1번 접시까지 먹은 경우로 초기화
		if (i < k) {
            // 초밥의 종류가 처음 등장했을 경우
			if (cnt[v[i]] == 0) { 
				eat_cnt++;
			}
			cnt[v[i]]++;
		}
	}

	int ans = eat_cnt; // 0번부터 k - 1번까지 먹은 초밥의 가짓수
	int i = 0;
    // 슬라이딩 윈도우
    // 0 ~ k - 1
    // 1 ~ k
    // 2 ~ k + 1
    // ...
    // N - 1 ~ N + k - 2
	while (1) {
		if (i >= N) {
			break;
		}

		cnt[v[i]]--; // 연속된 접시에서 빠질 초밥 제거
		if (cnt[v[i]] == 0) eat_cnt--; // 연속된 접시에서 빠질 초밥이 나온 횟수가 없을 경우

        // 연속된 접시에 추가 될 초밥이 나온 횟수가 없을 경우
        // i + k가 N을 넘을 경우도 있기에 나머지 연산 수행
		if (cnt[v[(i + k) % N]] == 0) {
			eat_cnt++;
			ans = max(ans, eat_cnt);
		}
		cnt[v[(i + k) % N]]++; // 연속된 접시에 추가 될 초밥의 횟수 추가
		
		i++;
	}

	cout << ans;
}