#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[100001]; // 트리를 인접리스트로 저장
bool visited[100001]; // 방문 여부

int max_dist_n = 1; // 트리의 지름이 되는 끝 노드, 초기값은 임의의 노드로 설정
int max_dist = 0; // 트리의 지름

void dfs(int n, int dist) {
	for (int i = 0; i < adj[n].size(); i++) {	
		if (!visited[adj[n][i].first]) { // 방문하지 않았을 경우
			if (max_dist < dist + adj[n][i].second) { // 현재까지의 거리가 더 클 경우
				max_dist_n = adj[n][i].first; 
				max_dist = dist + adj[n][i].second;
			}

			visited[adj[n][i].first] = true;
			dfs(adj[n][i].first, dist + adj[n][i].second);
		}		
	}
}

int main() {
	int V;
	cin >> V;

	int n, nn, d;
	for (int i = 0; i < V; i++) {
		cin >> n;
		while (1) {
			cin >> nn;
			if (nn == -1) break;
			cin >> d;
			
			adj[n].push_back({nn, d});
		}
	}

	visited[max_dist_n] = true;
	dfs(max_dist_n, 0);

	fill(visited, visited + V + 1, false); // visited 배열 초기화
	visited[max_dist_n] = true;
	dfs(max_dist_n, 0);

	cout << max_dist;
}