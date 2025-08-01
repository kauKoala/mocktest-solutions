#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N, K;
    cin >> N;
    cin >> K;

    vector<int> V(N); // 센서를 받을 벡터
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    sort(V.begin(), V.end());

    vector<int> dist(N - 1); // 정렬된 센서 사이의 거리
    for (int i = 1; i < N; i++) {
        dist.push_back(V[i] - V[i - 1]);
    }

    sort(dist.begin(), dist.end());

    int ans = 0;
    // 집중국 간의 거리가 멀 수록 집중국의 수신 가능영역의 거리는 줄어듦
    // 따라서 dist 원소의 개수인 N - 1에서 집중국과 집중국 사이의 개수 K - 1을 빼어 N - K까지만 ans로 더함 
    for (int i = 0; i < N - K; i++) {
        ans += dist[i];
    }

    cout << ans;
}