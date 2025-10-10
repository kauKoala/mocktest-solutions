#include <iostream>

using namespace std;

// 최대 공약수
int gcd(int a, int b) {
	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	// 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T;
	cin >> T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int lcm = M * N / gcd(M, N); // 최소 공배수

		int ans = -1;
		// x와 y가 같아질 때 까지 x에는 M을, y에는 N을 더함
		while (1) {
			// 최소 공배수 이내로 같아지지 않을 경우
			if (x > lcm || y > lcm) break;
			if (x == y) {
				ans = x;
				break;
			}
			else if (x < y) {
				x += M;
			}
			else {
				y += N;
			}

		}

		cout << ans << "\n";
	}
}