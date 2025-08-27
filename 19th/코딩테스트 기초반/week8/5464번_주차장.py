from collections import deque
import heapq

n, m = map(int, input().split())

fee = [int(input()) for _ in range(n)]  # 각 주차 자리의 단위 요금
weight = [0] + [int(input()) for _ in range(m)]  # 각 차량의 무게 (인덱스 맞추려고 0 추가)
order = [int(input()) for _ in range(m * 2)]  # 차량 입출차 순서

waiting = deque()  # 대기 차량 큐
hq = list(range(n))  # 사용 가능한 주차 공간(번호 작은 순서 우선)
heapq.heapify(hq)

result = 0  # 총 요금
parking_pos = [0] * (m + 1)  # 각 차량이 주차된 자리 기록

for i in order:
    if i > 0:  # 차량 i 입차
        if hq:  # 빈 주차 공간이 있으면
            pos = heapq.heappop(hq)  # 번호 가장 작은 자리 선택
            parking_pos[i] = pos
        else:  # 자리 없으면 대기열에 추가
            waiting.append(i)
    else:  # 차량 출차
        pos = parking_pos[-i]  # 해당 차량 주차 위치 확인
        result += weight[-i] * fee[pos]  # 요금 계산

        if waiting:  # 대기 차량이 있으면 바로 주차
            car = waiting.popleft()
            parking_pos[car] = pos
        else:  # 대기 차량 없으면 빈 자리로 돌려놓음
            heapq.heappush(hq, pos)

print(result)