#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[1001];
int cost[1001][1001]; // 노드 번호, 공짜로 연결해준 인터넷 선의 수 

int N, P, K;

void dijkstra(int n) {
    for (int i = 1; i <= N; i++) fill(cost[i], cost[i] + N, 123456789); // 모든 노드까지의 거리를 inf로 초기화

    priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {n, 0} }); // 원장선생님이 내는 비용의 최솟값, 노드 번호, 공짜로 연결해준 인터넷 선의 수
    cost[n][0] = 0;

    while (!pq.empty()) {
        int c = pq.top().first; // 원장선생님이 내는 비용의 최솟값
        int x = pq.top().second.first; // 노드 번호
        int free_cnt = pq.top().second.second; // 공짜로 연결해준 인터넷 선의 수
        pq.pop();

        if (cost[x][free_cnt] < c) continue; // 현재 노드까지 이동한 비용의 최솟값보다 클 경우 continue

        for (int i = 0; i < adj[x].size(); i++) {
            int nx = adj[x][i].first;
            int nc = adj[x][i].second;

            // 만약 다음 인터넷을 연결할 때 원장선생님이 내는 비용의 최솟값보다 큰 비용이 들어갈 경우 아래의 두 가지로 분기
            // 1. 공짜로 연결
            // 2. 원장선생님이 내는 비용의 최솟값을 갱신
            if (c < nc) { 
                if (free_cnt < K) { // 공짜로 연결해준 인터넷 선의 수가 K개보다 작을 경우
                    // 공짜로 연결시키는 경우
                    if (cost[nx][free_cnt + 1] > c) {
                        pq.push({ c, {nx, free_cnt + 1} });
                        cost[nx][free_cnt + 1] = c;
                    }
                }
                // 원장선생님이 내는 비용의 최솟값을 갱신하는 경우
                if (cost[nx][free_cnt] > nc) {
                    pq.push({ nc, {nx, free_cnt} });
                    cost[nx][free_cnt] = nc;
                }
            }
            // 만약 다음 인터넷을 연결할 때 원장선생님이 내는 비용의 최솟값보다 적은 비용이 들어갈 경우
            else {
                if (cost[nx][free_cnt] > c) {
                    pq.push({ c, {nx, free_cnt} });
                    cost[nx][free_cnt] = c;
                }
            }
        }

    }
}

int main() {
    cin >> N >> P >> K;

    int a, b, c;
    for (int i = 0; i < P; i++) {
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    dijkstra(1);

    int ans = 123456789;
    for (int i = 0; i < N; i++) ans = min(ans, cost[N][i]); // N번 노드까지 도달한 경우 중 K개보다 작은 수의 인터넷 선을 공짜로 연결한 경우도 고려

    if (ans == 123456789) cout << -1; // N번 노드까지 도달하지 못한 경우
    else cout << ans;
}