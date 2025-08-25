import sys
sys.setrecursionlimit(300000)

n, m, r = map(int, input().split())

# 인접 리스트
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

# 인접 리스트 내 각 노드를 내림차순 정렬 (문제 조건에 맞춰 DFS 순서 지정)
adj = [sorted(row, reverse=True) for row in adj]

idx, cnt = 1, 1
visited = [0] * (n + 1)
visited[r] = 1

def dfs(n):
    global idx, cnt
    global visited

    for i in adj[n]:  # 현재 노드와 연결된 노드 탐색
        if not visited[i]:  # 방문하지 않았다면
            cnt += 1  # 방문 순서 증가
            visited[i] = cnt  # 방문 순서 기록
            dfs(i)  # 재귀 호출

dfs(r)

# 1번 노드부터 n번 노드까지 방문 순서 출력
for i in range(n):
    print(visited[i+1])