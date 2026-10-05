import sys
input = sys.stdin.readline

# 7개의 정수 중 6개의 부호를 바꿨을 때 합의 최댓값을 구하는 문제

# 6개의 부호를 바꾼다는 것은 1개만 부호를 바꾸지 않고 남긴다는 것과 같다.
# 남긴 수는 더해지고 나머지 6개는 빼지므로, 가장 큰 수를 남겨야 합이 가장 커진다.

# 입력 처리
t = int(input())

for _ in range(t):
    a = list(map(int, input().split()))

    # 가장 큰 수는 그대로 더하고, 나머지 6개의 합은 부호를 바꿔서 뺀다
    ans = max(a) - (sum(a) - max(a))

    # 출력 처리
    print(ans)
