from collections import deque

dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

n, m = map(int, input().split())

arr = []
wolves = []  # 늑대 위치 저장

# 지도 입력 및 늑대 위치 기록
for i in range(n):
    line = list(input())
    for j, val in enumerate(line):
        if val == 'W':     
            wolves.append((i, j))
    arr.append(line)

visited = [[0] * m for _ in range(n)]

# BFS 함수: (x, y)에서 늑대 이동 시뮬레이션
def bfs(x, y):
    global visited

    q = deque()
    q.append((x, y))  # 시작 위치 큐에 추가
    visited[x][y] = 1  # 시작 위치 방문 처리

    while q:
        x, y = q.popleft()
        for i in range(4):  # 4방향 탐색
            nx, ny = x + dx[i], y + dy[i]

            # 격자 범위 벗어나면 스킵
            if not (0 <= nx < n and 0 <= ny < m):
                continue
            # 이미 방문했거나 산(#)이면 스킵
            if visited[nx][ny] or arr[nx][ny] == '#':
                continue

            # 빙판(+)이면 미끄러져 이동
            while arr[nx][ny] == '+':
                mx, my = nx + dx[i], ny + dy[i]
                if 0 <= mx < n and 0 <= my < m:
                    if arr[mx][my] == '#':  # 산 만나면 멈춤
                        break
                    else:  # 빙판 계속 이동
                        nx, ny = mx, my
                else:  # 범위 벗어나면 멈춤
                    break
            
            # 방문하지 않았고 산이 아니면 큐에 추가
            if not visited[nx][ny] and arr[nx][ny] != '#':
                visited[nx][ny] = 1
                q.append((nx, ny))

# 모든 늑대 위치에서 BFS 수행
for i, j in wolves:
    bfs(i, j)

# 늑대가 도달하지 않은 초원(.)은 안전한 곳(P)으로 표시
for i in range(n):
    for j in range(m):
        if arr[i][j] == '.' and not visited[i][j]:
            arr[i][j] = 'P'

for r in arr:
    print("".join(map(str, r)))