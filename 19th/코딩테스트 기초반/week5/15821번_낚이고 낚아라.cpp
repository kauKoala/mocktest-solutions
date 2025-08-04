#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 위해 헤더 파일 선언

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> V(N); // 벡터를 N 크기로 초기화

    int p, x, y;
    for (int i = 0; i < N; i++) {
        cin >> p;

        long long max_dist = 0; // 가장 먼 꼭짓점과의 거리의 제곱을 저장
        for (int j = 0; j < p; j++) {
            cin >> x >> y;
            // x나 y가 100,000일 경우 10,000,000,000으로 int 범위를 벗어나 오버플로우가 날 수 있음
            // 1LL을 곱하여 long long 타입임을 명시함
            long long dist = 1LL * x * x + 1LL * y * y; 
            max_dist = max(max_dist, dist); // 가장 먼 꼭짓점과의 거리의 제곱을 저장
        }
        V[i] = max_dist; // 벡터에 저장
    }

    sort(V.begin(), V.end());

    cout << V[K - 1] << ".00"; // 벡터에는 인덱스 0부터 저장되어 있기에 K - 1번째 인덱스가 정답
}