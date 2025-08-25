from collections import deque

dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

n, m = map(int, input().split())

a = []  # 지도 정보
q = deque()
for i in range(n):
    num = list(map(int, input()))  # 한 줄 입력 (숫자 하나씩)
    if 2 in num:  # 시작 지점 (값이 2인 곳 찾기)
        ix, iy = i, num.index(2)
    a.append(num)

check = [[0] * m for _ in range(n)]  # 방문 체크 배열

check[ix][iy] = 1
q.append(((ix, iy), 0))  # (좌표, 이동 거리)

while q:
    (pos, dist) = q.popleft()
    x, y = pos

    for k in range(4):  # 4방향 탐색
        nx, ny = x + dx[k], y + dy[k]
        # 범위 안에 있고, 방문 안 했고, 벽(1)이 아니면
        if 0 <= nx < n and 0 <= ny < m and not check[nx][ny] and a[nx][ny] != 1:
            if a[nx][ny] == 0:  # 빈 칸이면 계속 탐색
                check[nx][ny] = 1
                q.append(((nx, ny), dist + 1))
            else:  # 도착 지점(3 같은 값)이면
                print("TAK")
                print(dist + 1)
                exit(0)

print("NIE")  # 도달 불가능한 경우