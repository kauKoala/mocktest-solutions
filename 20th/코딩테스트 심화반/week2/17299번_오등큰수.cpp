#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	vector<int> v(N);
	vector<int> cnt(1000000); // 원소가 등장한 횟수 저장
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		cnt[v[i]]++; 
	}

	stack<int> s;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		// 벡터의 원소(스택의 top이 인덱스)의 개수보다 큰 벡터의 원소(i가 인덱스, 오등큰수)의 개수를 가진 경우
		while (!s.empty() && cnt[v[s.top()]] < cnt[v[i]]) {
			ans[s.top()] = v[i]; // 오등큰수 v[i]
			s.pop();
		}
		// 모든 현재 위치의 인덱스 push
		s.push(i);
	}

	// 오등큰수를 찾지 못했을 경우ㄴ
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}