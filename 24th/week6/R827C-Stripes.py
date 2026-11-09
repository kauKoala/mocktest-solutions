import sys
input = sys.stdin.readline

# 8x8 격자에 빨간 가로줄(R)과 파란 세로줄(B)을 차례로 칠했을 때, 마지막에 칠한 색을 구하는 문제

# 줄을 칠하면 그 줄이 지나가는 칸은 모두 새 색으로 덮인다.
# - 마지막에 빨간 가로줄을 칠했다면, 그 가로줄은 이후에 덮이지 않으므로 8칸 모두 R로 남는다.
# - 마지막에 파란 세로줄을 칠했다면, 그 세로줄이 모든 가로줄을 지나가며 한 칸씩 B로 덮는다.
#   따라서 8칸 모두 R인 가로줄은 하나도 남지 않는다.
# 즉, 8칸 모두 R인 가로줄이 하나라도 있으면 R, 없으면 B가 정답이다.

# 입력에서 각 테스트 케이스 앞에 빈 줄이 있으므로, 빈 줄은 건너뛰고 격자 줄만 읽는다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 변수 선언
    red_last = False   # 8칸 모두 R인 가로줄 존재 여부를 저장할 변수
    row_count = 0      # 지금까지 읽은 가로줄 수

    # 8개 가로줄 입력 처리
    while row_count < 8:
        row = input().strip()

        # 테스트 케이스 앞의 빈 줄은 건너뜀
        if row == "":
            continue

        row_count += 1

        # 이 가로줄이 8칸 모두 R이라면
        if row == "RRRRRRRR":
            red_last = True   # 빨간 줄이 마지막 처리
            # 남은 가로줄도 입력받아야 하므로 break 하지 않는다.

    # 출력 처리
    if red_last:
        print("R")
    else:
        print("B")
