#include <iostream>
#include <queue>

using namespace std;

// 우선순위큐를 오름차순으로 정렬, 최소 힙
// 각 음식별로 주문한 손님 번호를 저장
priority_queue<int, vector<int>, greater<int>> pq[200000]; 
int ans[100000];

int main() {
    // 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;

            // a번 음식에 i번 손님 저장
			pq[a].push(i);
		}
	}

	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
        // 음식을 주문한 손님이 존재할 경우
		if (!pq[b].empty()) {
			ans[pq[b].top()]++; // 제일 낮은 번호의 손님아 먹은 음식의 개수 증가
			pq[b].pop();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}