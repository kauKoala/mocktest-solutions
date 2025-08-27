import heapq

n, m = map(int, input().split())

# 인접 리스트 (양방향 그래프)
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

INF = int(1e9)
parent = [0] * (n + 1)  # 각 노드의 최단 경로 트리 상 부모 노드 저장

def dijkstra(start):
    global parent
    distance = [INF] * (n + 1)

    q = []
    heapq.heappush(q, (0, start))  # (거리, 시작 노드)
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in adj[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                parent[i[0]] = now  # 최단 경로 트리 부모 갱신
                heapq.heappush(q, (cost, i[0]))

dijkstra(1)

# 결과 출력: (n-1)개의 간선으로 최단 경로 트리 구성
print(n-1)
for i in range(2, n + 1):
    print(i, parent[i])  # (자식, 부모)