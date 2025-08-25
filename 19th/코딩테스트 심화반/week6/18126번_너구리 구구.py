import sys
sys.setrecursionlimit(25000000)

n = int(input())

# 인접 리스트
adj = [[] for _ in range(n + 1)]

# 간선 정보 입력 (a - b : 가중치 c)
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

visited = [0] * (n + 1)
visited[1] = 1  # 시작 노드 방문으로 표시
max_dist = 0  # 트리에서 가장 먼 거리 저장

def dfs(m, dist):
    global max_dist
    global visited
    for i, j in adj[m]:  # i: 다음 노드, j: 간선 가중치
        if not visited[i]:
            max_dist = max(max_dist, dist + j)  # 현재까지 거리 최댓값 갱신
            visited[i] = 1
            dfs(i, dist + j)  # DFS 계속 탐색

# 루트(1번)에서 출발
dfs(1, 0)
print(max_dist)