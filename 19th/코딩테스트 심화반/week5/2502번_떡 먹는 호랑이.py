d, k = map(int, input().split())  # d: 마지막 날 (1-based), k: 마지막 날에 먹은 떡의 개수

dp = [0 for _ in range(d)]        # 각 날짜별 떡 개수를 저장할 리스트
dp[0], dp[1] = 1, 1               # 첫째 날과 둘째 날의 떡 개수를 임의로 1, 1로 시작

while 1:
    for i in range(2, d):         # 셋째 날부터 d번째 날까지 떡 개수 계산
        dp[i] = dp[i-1] + dp[i-2] # 점화식: 오늘 먹은 떡 = 전날 + 전전날

    if dp[d-1] == k:              # d번째 날에 먹은 떡이 정확히 k개면 조건 만족
        break
    elif dp[d-1] < k:             # 아직 부족하면 둘째 날 떡 개수(dp[1]) 증가
        dp[1] += 1
    else:                         # 초과한 경우, 첫째 날 개수 증가하고 둘째 날은 다시 첫째 날로 초기화
        dp[0] += 1
        dp[1] = dp[0]

print(dp[0])  # 첫째 날 떡 개수 출력
print(dp[1])  # 둘째 날 떡 개수 출력