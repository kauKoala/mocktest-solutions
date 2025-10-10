#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string q;
	int s, b;
	vector<pair<string, pair<int, int>>> v; // 질문, 스트라이크, 볼
	for (int i = 0; i < N; i++) {
		cin >> q >> s >> b;
		v.push_back({ q, { s, b } });
	}

	int ans = 0;
	// 각 자리 수가 서로 다른 1 ~ 9로 이루어진 모든 세자리 수에 대해 brute force
	for (int num = 100; num < 1000; num++) {
		string str_num = to_string(num);
		// 각 자리 수가 서로 다르지 않을 경우
		if (str_num[0] == str_num[1] || str_num[0] == str_num[2] || str_num[1] == str_num[2]) continue;
		// 0이 존재할 경우
		if (str_num[0] == '0' || str_num[1] == '0' || str_num[2] == '0') continue;

		bool possible = true;
		// 모든 질문에 대해 정합해야만 가능한 답이 됨
		for (int i = 0; i < N; i++) {
			q = v[i].first;
			int sans = v[i].second.first; // 질문에 따른 스트라이크 개수
			int bans = v[i].second.second; // 질문에 따른 볼 개수
			int scnt = 0; 
			int bcnt = 0;
			for (int j = 0; j < 3; j++) {
				if (q[j] == str_num[j]) scnt++;
				if (q[j] == str_num[(j + 1) % 3] || q[j] == str_num[(j + 2) % 3]) bcnt++;
			}

			if (sans != scnt || bans != bcnt) {
				possible = false;
				break;
			}
		}
		if (possible) {
			ans++;
		}
	}

	cout << ans;
}