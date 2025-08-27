from collections import deque

# 8방향 (상하좌우 + 대각선)
dx, dy = [0, 0, 1, -1, -1, 1, -1, 1], [1, -1, 0, 0, 1, 1, -1, -1]

while 1:
    w, h = map(int, input().split())
 
    # 종료 조건
    if w == 0 and h == 0:
        break

    land = [list(map(int, input().split())) for _ in range(h)]  # 지도 입력
    check = [[0] * w for _ in range(h)]  # 방문 체크
    cnt = 0  # 섬 개수

    q = deque()
    
    for i in range(h):
        for j in range(w):
            if not check[i][j] and land[i][j]:  # 방문 안 했고 땅(1)일 경우
                q.append((i, j))
                check[i][j] = 1  # 시작점 방문 체크
                cnt += 1  # 새로운 섬 발견
            
            # BFS
            while q:
                x, y = q.popleft()
                for k in range(8):  # 8방향 탐색
                    nx, ny = x + dx[k], y + dy[k]
                    if 0 <= nx < h and 0 <= ny < w and land[nx][ny] == 1 and not check[nx][ny]:
                        check[nx][ny] = 1
                        q.append((nx, ny))
    
    print(cnt)