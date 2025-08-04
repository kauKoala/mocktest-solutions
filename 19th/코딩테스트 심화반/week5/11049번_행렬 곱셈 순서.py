n = int(input())

matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

dp = [[0 for _ in range(n)] for _ in range(n)]

# length: 부분 행렬 체인의 길이 (1부터 n-1까지)
for length in range(1, n):
    for i in range(n - length):  # 시작 인덱스
        j = i + length  # 끝 인덱스
        dp[i][j] = float('inf')  # 최소값 갱신을 위해 초기값을 무한대로 설정
        for k in range(i, j):
            # 곱셈 연산 수 계산:
            # dp[i][k]: i~k까지의 곱셈 비용
            # dp[k+1][j]: k+1~j까지의 곱셈 비용
            # matrix[i][0] * matrix[k][1] * matrix[j][1]: 현재 분할에서 발생하는 곱셈 비용
            cost = dp[i][k] + dp[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]
            dp[i][j] = min(dp[i][j], cost)

# 최종 결과: 전체 행렬 곱에서 최소 연산 수
print(dp[0][n-1])