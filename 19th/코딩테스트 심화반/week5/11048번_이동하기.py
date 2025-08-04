n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            continue  # 시작점은 그대로 둔다
        elif i == 0:
            # 첫 번째 행은 왼쪽에서만 올 수 있다
            arr[i][j] = arr[i][j] + arr[i][j-1]
        elif j == 0:
            # 첫 번째 행은 왼쪽에서만 올 수 있다
            arr[i][j] = arr[i][j] + arr[i-1][j]
        else:
            # 첫 번째 열은 위쪽에서만 올 수 있다
            arr[i][j] = max(arr[i-1][j-1], arr[i-1][j], arr[i][j-1]) + arr[i][j]

# 마지막 칸에 도달했을 때의 최대 사탕 수 출력
print(arr[n-1][m-1])