#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;
vector<int> l_v;
vector<int> r_v;

int N, C;

// 생성할 벡터 레퍼런스, 현재 무게, 현재 idx, 종료 시점
void make_vector(vector<int>& v, int current_weight, int idx, int end) {
	if (idx == end) {
		v.push_back(current_weight);
		return;
	}	

	// 현재 idx의 값이 들어가지 않는 경우
	make_vector(v, current_weight, idx + 1, end); 
	
	// 현재 idx의 값이 들어가는 경우, 가능한 무게 C를 넘지 않을 때 호출
	if (current_weight + V[idx] <= C) make_vector(v, current_weight + V[idx], idx + 1, end);
}

int main() {
	cin >> N >> C;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		V.push_back(num);
	}

	// N이 최대 30이기에 O(2^30)의 bruteforce의 경우 시간 복잡도가 발생할 수 있음
	// 둘로 나누어 시간 복잡도를 O(2^15)로 줄임
	make_vector(l_v, 0, 0, N / 2); // 0부터 N / 2까지
	make_vector(r_v, 0, N / 2, N); // N / 2부터 N까지

	sort(l_v.begin(), l_v.end()); // 탐색을 위해 sort
	sort(r_v.begin(), r_v.end()); // 탐색을 위해 sort

	int ans = 0;

	for (int i = 0; i < r_v.size(); i++) {
		// upper_bound 함수는 내부적으로 이진 탐색 사용
		// C - r_v[i]보다 큰 index를 반환
		// 해당 index 전까지는 모두 정답 (l_v[i] + r_v[i] <= C)
		ans += upper_bound(l_v.begin(), l_v.end(), C - r_v[i]) - l_v.begin();
	}

	/* 투포인터 풀이법
	int i = 0, j = r_v.size() - 1;
	while (1) {
		if (i >= l_v.size() || j < 0) break;

		if (l_v[i] + r_v[j] <= C) {
			ans += j + 1;
			i++;
		}
		else {
			j--;
		}
	}
	*/

	cout << ans;
}