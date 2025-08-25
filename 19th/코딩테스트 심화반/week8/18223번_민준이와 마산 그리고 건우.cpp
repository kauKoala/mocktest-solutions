#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[5001];
int cost[5001];

void dijkstra(int n, int V) {
    fill(cost, cost + V + 1, 123456789); // 모든 노드까지의 거리를 inf로 초기화
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
            }
        }
    }
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, P;
    cin >> V >> E >> P;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    dijkstra(1, V);

    int cost1P = cost[P]; // 1번 노드에서 P번 노드로 이동하는 최소 비용
    int cost1V = cost[V]; // 1번 노드에서 V번 노드로 이동하는 최소 비용

    dijkstra(P, V);

    int costPV = cost[V]; // P번 노드에서 V번 노드로 이동하는 최소 비용

    // 1번에서 P번 노드로 이동하는 최솟값 + P번 노드에서 V번 노드로 이동하는 최솟값 = 1번에서 V번 노드로 이동하는 최솟값일 경우
    if (cost1V == cost1P + costPV) cout << "SAVE HIM"; 
    else cout << "GOOD BYE";
}