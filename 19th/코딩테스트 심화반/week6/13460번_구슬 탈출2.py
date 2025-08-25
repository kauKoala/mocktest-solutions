from collections import deque

n, m = map(int, input().split())
board = [list(input().strip()) for _ in range(n)]

# 빨간 구슬(R), 파란 구슬(B) 좌표 찾기
for i in range(n):
    for j in range(m):
        if board[i][j] == 'R':
            rx, ry = i, j
        if board[i][j] == 'B':
            bx, by = i, j

# 4차원 visited[rx][ry][bx][by]
visited = [[[[0] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]

# 이동 방향 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def move(x, y, dx, dy):
    cnt = 0
    # 벽(#) 만나기 전까지 이동, 구멍(O) 만나면 멈춤
    while board[x + dx][y + dy] != '#' and board[x][y] != 'O':
        x += dx
        y += dy
        cnt += 1
    return x, y, cnt

q = deque()
q.append((rx, ry, bx, by, 0))
visited[rx][ry][bx][by] = 1

while q:
    rx, ry, bx, by, dist = q.popleft()

    if dist >= 10:   # 10번 넘으면 실패
        break

    for i in range(4):  # 네 방향 시도
        nrx, nry, rmove = move(rx, ry, dx[i], dy[i])
        nbx, nby, bmove = move(bx, by, dx[i], dy[i])

        # 파란 구슬이 구멍에 빠지면 실패
        if board[nbx][nby] == 'O':
            continue
        # 빨간 구슬만 구멍에 빠졌으면 성공
        if board[nrx][nry] == 'O':
            print(dist + 1)
            exit(0)

        # 같은 위치에 있으면 → 더 많이 움직인 구슬을 한 칸 뒤로
        if nrx == nbx and nry == nby:
            if rmove > bmove:
                nrx -= dx[i]
                nry -= dy[i]
            else:
                nbx -= dx[i]
                nby -= dy[i]

        if not visited[nrx][nry][nbx][nby]:
            visited[nrx][nry][nbx][nby] = 1
            q.append((nrx, nry, nbx, nby, dist + 1))

print(-1)
