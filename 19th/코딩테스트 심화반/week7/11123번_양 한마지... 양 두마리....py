from collections import deque

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

for _ in range(int(input())):
    h, w = map(int, input().split())
    grid = []
    for _ in range(h):
        grid.append(list(input()))
    
    cnt = 0
    check = [[0] * w for _ in range(h)]

    q = deque()
    for i in range(h):
        for j in range(w):
            # 방문하지 않았고 양('#') 이면 BFS 시작
            if check[i][j] == 0 and grid[i][j] == '#':
                cnt += 1  # 양 무리 개수 추가
                check[i][j] = 1  # 방문 처리

                q.append((i, j))
                while q:
                    x, y = q.popleft()
                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if 0 <= nx < h and 0 <= ny < w and grid[nx][ny] == '#' and not check[nx][ny]:
                            check[nx][ny] = 1
                            q.append((nx, ny))
    
    print(cnt)