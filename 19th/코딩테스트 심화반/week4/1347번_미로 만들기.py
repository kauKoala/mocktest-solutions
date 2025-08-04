n = int(input())
hongjun = list(input())

# n*2 x n*2 크기의 격자판 생성, 초기값은 모두 '#'
arr = [['#' for _ in range(2 * n)] for _ in range(2 * n)]

# 시작 위치는 중앙에서 한 칸 왼쪽 위 (좌표 보정을 위해 n-1 사용)
x, y = n - 1, n - 1
arr[y][x] = '.'  # 시작 위치는 방문 표시

# 방향 벡터 (0:남, 1:서, 2:북, 3:동)
dx = [0, -1, 0, 1]  # x 방향 이동
dy = [1, 0, -1, 0]  # y 방향 이동
direction = 0  # 초기 방향은 남쪽

# 그려진 경로의 최소/최대 좌표값 추적 (출력 범위 조절용)
max_x, max_y, min_x, min_y = x, y, x, y

# 명령어 하나씩 처리
for i in hongjun:
    if i == 'F':  # 앞으로 이동
        x += dx[direction]
        y += dy[direction]
        arr[y][x] = '.'  # 이동한 위치 표시
        # 최소/최대 범위 업데이트
        min_x = min(min_x, x)
        max_x = max(max_x, x)
        min_y = min(min_y, y)
        max_y = max(max_y, y)
    elif i == 'R':  # 오른쪽 회전
        direction += 1
        direction %= 4  # 방향을 0~3으로 유지
    else:  # 'L' (왼쪽 회전)
        direction -= 1
        direction %= 4

# 경로가 그려진 부분만 출력
for i in range(min_y, max_y + 1):
    for j in range(min_x, max_x + 1):
        print(arr[i][j], end="")
    print()