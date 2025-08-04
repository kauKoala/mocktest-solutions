#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 위해 헤더 파일 선언

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> V(N + M); // 벡터를 N + M 크기로 초기화

    for (int i = 0; i < N; i++) {
        cin >> V[i]; // 0 ~ N - 1까지 입력 받음
    }
    for (int i = 0; i < M; i++) {
        cin >> V[i + N]; // N ~ M - 1까지 입력 받음
    }

    sort(V.begin(), V.end()); // 정렬

    for (int i = 0; i < N + M; i++) {
        cout << V[i] << " ";
    }
}