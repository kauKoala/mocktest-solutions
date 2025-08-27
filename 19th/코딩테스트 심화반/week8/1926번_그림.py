from collections import deque
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]  # 상하좌우 방향

n, m = map(int, input().split())

arr = []
for i in range(n):
    row = list(map(int, input().split()))
    arr.append(row)

check = [[0] * m for _ in range(n)]  # 방문 여부 + 영역 번호 기록
val = 1  # 현재 그림 번호 (1번부터 시작)
max_count = 0  # 가장 큰 그림의 넓이

q = deque()

for i in range(n):
    for j in range(m):
        # 방문하지 않은 그림 시작점 발견
        if check[i][j] == 0 and arr[i][j] == 1:
            check[i][j] = val
            q.append((i, j))
            count = 1  # 현재 그림의 넓이

            # BFS로 연결된 그림 탐색
            while q:
                x, y = q.popleft()
                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1 and not check[nx][ny]:
                        check[nx][ny] = val
                        count += 1
                        q.append((nx,ny))
            
            # 새로운 그림 하나 탐색 끝
            val += 1 
            max_count = max(max_count, count)  # 최대 넓이 갱신

print(val - 1)
print(max_count)