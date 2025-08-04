from collections import deque

# 입력: n: 지도 크기, m: 승객 수, fuel: 초기 연료
n, m, fuel = map(int, input().split())
b_map = [[0] * (n + 1)]  # 1-indexed를 위한 더미 행 추가

# 지도 정보 입력 (1은 벽이므로 -1로 치환)
for _ in range(n):
    row = list(map(int, input().split()))
    b_map.append([0] + [(-1 if x == 1 else x) for x in row])

# 택시 시작 위치
r, c = map(int, input().split())

# 승객 정보 저장 및 시작 위치에 번호 표시
passenger = []
for i in range(m):
    s_r, s_c, e_r, e_c = map(int, input().split())
    passenger.append((e_r, e_c))          # 목적지만 저장
    b_map[s_r][s_c] = i + 1               # 출발 위치에 승객 번호 등록

# 방향 벡터 (우, 하, 좌, 상)
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

find_path = False

# 승객 수만큼 반복 (각 승객을 찾아서 목적지까지 이동)
for _ in range(m):
    q1 = deque()
    q2 = deque()
    visited1 = [[0 for _ in range(21)] for _ in range(21)]
    visited2 = [[0 for _ in range(21)] for _ in range(21)]

    find_path = False
    used_fuel1 = 401  # 승객 찾을 때 연료 사용량 초기화

    # 현재 위치에 승객이 있으면 바로 태움
    if b_map[r][c] >= 1:
        find_path = True
        customer_num = b_map[r][c]
        used_fuel1 = 0
    else:
        # BFS 시작
        q1.append(((r, c), 0))
        visited1[r][c] = 1

    # 승객 찾기 BFS
    while q1:
        pos, depth = q1.popleft()

        if (fuel <= depth or depth >= used_fuel1):
            break  # 연료 부족하거나 최단거리보다 멀면 중단

        for i in range(4):
            nr, nc = pos[0] + dr[i], pos[1] + dc[i]

            if (1 <= nr <= n and 1 <= nc <= n and b_map[nr][nc] != -1 and not visited1[nr][nc]):
                if 1 <= b_map[nr][nc]:
                    if not find_path:
                        # 처음 찾은 승객이면 등록
                        find_path = True
                        customer_num = b_map[nr][nc]
                        r = nr
                        c = nc
                        used_fuel1 = depth + 1
                    else:
                        # 거리 같을 경우 행, 열 우선순위 비교
                        if nr < r or (nr == r and nc < c):
                            customer_num = b_map[nr][nc]
                            r = nr
                            c = nc
                else:
                    # 빈 칸이면 계속 탐색
                    q1.append(((nr, nc), depth + 1))
                    visited1[nr][nc] = True

    if not find_path:
        break  # 태울 승객 못 찾은 경우 실패
    b_map[r][c] = 0      # 승객 태웠으므로 지도에서 제거
    fuel -= used_fuel1   # 연료 차감

    find_path = False
    used_fuel2 = 401     # 도착지까지 연료 사용량 초기화

    # 승객 목적지까지 BFS
    q2.append(((r, c), 0))
    visited2[r][c] = True

    while q2:
        pos, depth = q2.popleft()

        if (fuel <= depth or find_path):
            break  # 연료 부족하거나 이미 도착한 경우 중단

        for i in range(4):
            nr, nc = pos[0] + dr[i], pos[1] + dc[i]

            if (1 <= nr <= n and 1 <= nc <= n and b_map[nr][nc] != -1 and not visited2[nr][nc]):
                destination_r, destination_c = passenger[customer_num - 1]

                if nr == destination_r and nc == destination_c:
                    # 목적지 도착
                    find_path = True
                    r = nr
                    c = nc
                    used_fuel2 = depth + 1
                else:
                    q2.append(((nr, nc), depth + 1))
                    visited2[nr][nc] = True

    if not find_path:
        break  # 목적지 못 감
    fuel -= used_fuel2           # 연료 차감
    fuel += used_fuel2 * 2       # 연료 보충

# 실패 시 -1 출력
if not find_path:
    print(-1)
else:
    print(fuel)
