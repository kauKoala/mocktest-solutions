n, m, b = map(int, input().split())

block = []
for _ in range(n):
    block.append(list(map(int, input().split())))

min_time = 1e9  # 최소 시간을 아주 큰 값으로 초기화
max_height = -1  # 가장 높은 높이를 저장할 변수

# 가능한 높이(0 ~ 256) 모두 시도
for height in range(257):
    job_one_cnt = 0  # 작업1 수
    job_two_cnt = 0  # 작업2 수

    # 모든 좌표 순회
    for i in range(n):
        for j in range(m):
            if block[i][j] > height:  # 현재 높이가 목표 높이보다 높으면 블록 제거 
                job_one_cnt += (block[i][j] - height)
            elif block[i][j] < height:  # 현재 높이가 목표 높이보다 낮으면 블록 설치 
                job_two_cnt += (height - block[i][j])
    
    # 인벤토리 블록으로 작업이 가능한 경우 (남는 블록 + 인벤토리 블록으로 부족한 만큼 채울 수 있는지 확인)
    if b - (job_two_cnt - job_one_cnt) >= 0:
        if min_time >= (job_one_cnt * 2 + job_two_cnt):
            min_time = job_one_cnt * 2 + job_two_cnt
            max_height = height

print(min_time, max_height)