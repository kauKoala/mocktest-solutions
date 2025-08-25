from collections import deque

n = int(input())

adj = [[] for _ in range(n + 1)]  # 인접 리스트
visited = [0] * (n + 1)

for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

q = deque()
cnt = 0  # 리프 노드까지의 거리 합
visited[1] = 1  # 시작 노드 방문 표시
q.append((1, 0))  # (현재 노드, 거리)

while q:
    num, dist = q.popleft()

    leaf = True  # 현재 노드가 리프 노드인지 판별
    for v in adj[num]:
        if not visited[v]:
            leaf = False
            visited[v] = 1
            q.append((v, dist + 1))
    
    if leaf:  # 리프 노드라면
        cnt += dist  # 거리 누적

# 리프 노드까지의 거리 합(cnt)이 홀수면 이길 수 있음
if cnt % 2 == 1:
    print("Yes")
else:
    print("No")