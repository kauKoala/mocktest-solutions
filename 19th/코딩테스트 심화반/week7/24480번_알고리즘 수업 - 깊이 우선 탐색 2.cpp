#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
int visited[100001]; // visited에 방문 순서를 함께 저장

int cnt = 0; // 현재 방문 횟수

void dfs(int n) {
    int adj_cnt = adj[n].size(); // 인접 정점 개수
    for (int i = 0; i < adj_cnt; i++) {
        int adj_n = adj[n][i]; // 인접 정점
        if (visited[adj_n] == 0) { // 아직 방문하지 않은 경우
            cnt++;
            visited[adj_n] = cnt;

            dfs(adj_n);
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    int n1, n2;
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for (int i = 1; i <= N; i++) {
        // 모든 인접 정점을 내림차순으로 정렬
        sort(adj[i].begin(), adj[i].end(), greater<>()); 
    }

    cnt++;
    visited[R] = cnt; // 시작 정점의 방문 순서는 1

    dfs(R);

    // 방문 순서를 정점 순서대로 출력
    for (int i = 1; i <= N; i++) { 
        cout << visited[i] << "\n";
    }
}