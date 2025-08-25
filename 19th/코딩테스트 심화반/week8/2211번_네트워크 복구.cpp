#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[1001];
int cost[1001];
int parent[1001]; // 역추적

int N, M;

void dijkstra(int n) {
    fill(cost, cost + N + 1, 123456789); // 모든 노드까지의 거리를 inf로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, n }); // 이동한 비용의 최솟값, 노드 번호
    cost[n] = 0;

    while (!pq.empty()) {
        int c = pq.top().first; // 이동한 비용의 최솟값
        int x = pq.top().second; // 노드 번호
        pq.pop();

        if (cost[x] < c) continue; // 현재 노드까지 이동한 비용의 최솟값보다 클 경우 continue

        for (int i = 0; i < adj[x].size(); i++) {
            int nx = adj[x][i].first;
            int nc = c + adj[x][i].second; // 현재까지의 이동한 비용 + 다음 노드로 이동할 비용

            // 이동한 비용의 최솟값을 갱신하는 경우
            if (cost[nx] > nc) {
                pq.push({ nc, nx });
                cost[nx] = nc;
                parent[nx] = x; // 어느 경로에서 왔는지 저징
            }
        }
    }
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        adj[A].push_back({ B, C });
        adj[B].push_back({ A, C });
    }

    dijkstra(1);

    // 최소 개수의 회선만을 복구해야 하기에 간선이 N - 1개인 사이클이 없는 그래프
    cout << N - 1 << "\n";
    for (int i = 2; i <= N; i++) {
        cout << i << " " << parent[i] << "\n"; // 각 노드가 어느 경로에서 왔는지 출력
    }
}