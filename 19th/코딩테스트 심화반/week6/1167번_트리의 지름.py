import sys
sys.setrecursionlimit(200000)

v = int(input())

# 인접 리스트 생성
adj = [[] for _ in range(v + 1)]
for _ in range(v):
    readline = list(map(int, input().split()))
    for i in range(len(readline) // 2 - 1):
        adj[readline[0]].append((readline[2 * i + 1], readline[2 * i + 2]))
        adj[readline[2 * i + 1]].append((readline[0], readline[2 * i + 2]))

idx, max_dist = 1, 0
visited = [0] * (v + 1)
visited[1] = 1

def dfs(n, dist):
    global idx, max_dist
    global visited

    # 현재 노드 n에서 갈 수 있는 모든 인접 노드 탐색
    for i, j in adj[n]:  # (i: 다음 노드, j: 거리)
        if not visited[i]:
            visited[i] = 1
            sum_dist = dist + j
            if sum_dist > max_dist:  # 더 멀리 도달하면 갱신
                max_dist = sum_dist
                idx = i
            dfs(i, dist + j)

# 1단계: 임의의 노드(1)에서 가장 먼 노드 찾기
dfs(1, 0)

# 2단계: 그 노드(idx)에서 가장 먼 노드를 찾아 거리 측정 → 트리의 지름
visited = [0] * (v + 1)
visited[idx] = 1
dfs(idx, 0)

print(max_dist)