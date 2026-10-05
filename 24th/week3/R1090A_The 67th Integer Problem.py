import sys
input = sys.stdin.readline

# 정수 x가 주어질 때 min(x, y)가 최대가 되는 y를 구하는 문제

# min(x, y)는 x보다 커질 수 없으므로, y가 x보다 크거나 같으면 min(x, y) = x로 최댓값이 된다.
# y는 -67 ~ 67 범위 안에 있어야 하므로, 범위 안에서 항상 x 이상인 67을 출력한다.
# (y = x + 1을 출력하면 x = 67일 때 68이 되어 범위를 벗어나므로 틀린다)

# 입력 처리
t = int(input())

for _ in range(t):
    x = int(input())

    # 출력 처리
    print(67)
