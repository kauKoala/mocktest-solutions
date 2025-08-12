#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[500001]; // 트리를 인접리스트로 저장
bool visited[500001]; // 방문 여부

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int n1, n2;
    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    queue<pair<int, int>> q;

    q.push({ 1, 0 }); // 루트 노드부터 시작
    visited[1] = true;

    int cnt = 0;
    while (!q.empty()) {
        int n = q.front().first;
        int dist = q.front().second;
        q.pop();

        bool leaf = true; 
        for (auto v : adj[n]) { // n번 노드와 연결된 노드 v
            if (!visited[v]) {
                leaf = false;
                visited[v] = true;
                q.push({ v, dist + 1 });
            }
        }
        if (leaf) cnt += dist; // 만약 리프 노드라면 루트로부터의 거리를 저장
    }

    if (cnt % 2 == 1) cout << "Yes";
    else cout << "No";
}