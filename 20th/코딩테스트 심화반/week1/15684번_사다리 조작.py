n, m, h = map(int, input().split())

# 정답 초기값 4 (문제에서 최대 3개까지만 추가 가능)
ans = 4

# 백트래킹 함수 정의
# idx: 현재까지 추가한 가로선 개수
# r, c: 현재 탐색 시작 위치 (행, 열)
def back_tracking(idx, r, c):
    global board, ans  # 전역 변수 사용 선언

    # 현재 상태에서 사다리가 모두 올바른지 확인
    possible = True
    for start in range(1, n + 1):  # 각 세로선 시작점
        pos = start
        for i in range(1, h + 1):  # 각 행에서 이동
            if board[i][pos]:       # 오른쪽으로 가는 가로선이 있으면
                pos += 1
            elif board[i][pos - 1]: # 왼쪽으로 가는 가로선이 있으면
                pos -= 1
        
        # 최종 도착점이 출발점과 다르면 실패
        if pos != start:
            possible = False
            break
    
    # 모든 세로선이 올바른 위치로 도착하면 정답 갱신
    if possible:
        ans = min(ans, idx)
        return
    
    # 추가 가로선이 3개 이상이거나 이미 현재 ans보다 크면 더 탐색하지 않음
    if idx == 3 or idx >= ans:
        return
    
    # 가능한 위치에 가로선을 추가하며 재귀 탐색
    for i in range(r, h + 1):  # 행
        k = 1
        if i == r:  # 첫 행이면 이전 열부터 시작
            k = c
        for j in range(k, n):  # 열
            # 좌우에 가로선이 없는 경우에만 추가 가능
            if not board[i][j] and not board[i][j + 1] and not board[i][j - 1]:
                board[i][j] = True       # 가로선 추가
                back_tracking(idx + 1, i, j)  # 재귀 호출
                board[i][j] = False      # 백트래킹 후 되돌리기

# 보드 초기화: 31행, 11열 (문제 제한에 맞춘 충분히 큰 배열)
board = [[0] * 11 for _ in range(31)]

# 기존에 존재하는 가로선 입력
for i in range(m):
    a, b = map(int, input().split())
    board[a][b] = True

# 백트래킹 시작
back_tracking(0, 1, 1)

# 결과 출력
# ans가 4보다 작으면 최소 추가 개수 출력, 그렇지 않으면 -1
if ans < 4:
    print(ans)
else:
    print(-1)