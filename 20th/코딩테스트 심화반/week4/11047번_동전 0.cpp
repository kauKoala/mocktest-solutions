#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    // K보다 작거나 같으면서 가치가 가장 큰 동전의 idx
    int idx = -1;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];

        if (v[i] <= K) idx = i; 
    }

    int ans = 0;
    while (1) {
        if (idx == -1) break;

        // K보다 작거나 같으면서 가치가 가장 큰 동전부터 사용
        if (v[idx] <= K) {
            ans += K / v[idx];
            K %= v[idx];
        }
        idx--;
    }

    cout << ans;
}