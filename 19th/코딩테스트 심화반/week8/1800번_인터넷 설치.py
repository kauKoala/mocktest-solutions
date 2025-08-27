import heapq

n, p, k = map(int, input().split())

adj = [[] for _ in range(n + 1)]
for _ in range(p):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

INF = int(1e9)
# distance[x][f] = x번 노드에 f개의 무료 케이블을 사용해서 도달했을 때 최소 비용
distance = [[INF] * (n + 1) for _ in range(n + 1)]

def dijkstra(start):
    global distance
    q = []
    heapq.heappush(q, (0, (start, 0)))  # (현재 비용, (노드, 무료 사용 횟수))
    distance[start][0] = 0

    while q:
        cost, (x, free_cnt) = heapq.heappop(q)

        if distance[x][free_cnt] < cost:
            continue

        for nx, nc in adj[x]:

            # 현재 간선 비용이 더 크다면, 무료 케이블 사용 고려
            if cost < nc:
                # 무료 케이블 아직 쓸 수 있으면
                if free_cnt < k:
                    if distance[nx][free_cnt + 1] > cost:
                        heapq.heappush(q, (cost, (nx, free_cnt + 1)))
                        distance[nx][free_cnt + 1] = cost
                
                # 무료 안 쓰고 그냥 해당 간선 비용 사용
                if distance[nx][free_cnt] > nc:
                    heapq.heappush(q, (nc, (nx, free_cnt)))
                    distance[nx][free_cnt] = nc
            
            # 현재 경로 비용이 더 작거나 같은 경우
            else:
                if distance[nx][free_cnt] > cost:
                    heapq.heappush(q, (cost, (nx, free_cnt)))
                    distance[nx][free_cnt] = cost

dijkstra(1)

# N번 노드에 도달 가능한 모든 경우 중 최소 비용 선택
ans = INF
for i in range(n):
    ans = min(ans, distance[n][i])

if ans == INF:
    print(-1)
else:
    print(ans)