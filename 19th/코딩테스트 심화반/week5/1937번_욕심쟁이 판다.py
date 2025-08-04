import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline 

n = int(input())

bamboo = []
for _ in range(n):
    bamboo.append(list(map(int, input().split())))

# 상하좌우 이동 방향 정의
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

dp = [[0] * n for _ in range(n)]

def dfs(x, y):
    if dp[x][y]:  # 이미 계산한 적이 있다면 바로 반환
        return dp[x][y]
    
    dp[x][y] = 1  # 최소 생존 일 수는 1 (자기 자신만 있을 때)
    for k in range(4):  # 4방향 탐색
        nx, ny = x + dx[k], y + dy[k]
        # 인접한 칸이 범위 내에 있고, 대나무 양이 더 많다면 이동 가능
        if 0 <= nx < n and 0 <= ny < n and bamboo[nx][ny] > bamboo[x][y]:
            # 이동한 칸에서의 결과와 비교해 최대값 갱신
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1)
    
    return dp[x][y]

max_cnt = 0

# 모든 위치에서 DFS 수행하며 최댓값 갱신
for i in range(n):
    for j in range(n):
        max_cnt = max(max_cnt, dfs(i, j))

print(max_cnt)