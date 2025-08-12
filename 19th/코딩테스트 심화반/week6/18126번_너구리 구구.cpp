#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[5001]; // 그래프를 인접리스트로 저장
bool visited[5001]; // 방문 여부

long long max_dist = 0; // 가장 먼 방까지의 거리

void dfs(int n, long long dist) {
    for (int i = 0; i < adj[n].size(); i++) {
        if (!visited[adj[n][i].first]) { // 방문하지 않았을 경우
            if (max_dist < dist + 1LL * adj[n][i].second) { // 현재까지의 거리가 더 클 경우
                max_dist = dist + 1LL * adj[n][i].second;
            }

            visited[adj[n][i].first] = true;
            dfs(adj[n][i].first, dist + 1LL * adj[n][i].second);
        }
    }
}

int main() {
    int N;
    cin >> N;

    int A, B, C;
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    visited[1] = true;
    dfs(1, 0);

    cout << max_dist;
}