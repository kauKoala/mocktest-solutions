#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num;
    for (int i = 1; i <= N * N; i++) {
        cin >> num;

        pq.push(num);

        if (i > N) pq.pop(); // i가 N보다 클 경우 N번째 큰 수는 절대로 우선순위큐의 top이 될 수 없다.
    }

    cout << pq.top(); // 전부 pop하고 난 후의 top이 곧 N번째 큰 수
}