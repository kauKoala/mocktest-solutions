import sys
input = sys.stdin.readline

# l1 <= x <= r1, l2 <= y <= r2 이고, y / x = k^n (n은 0 이상의 정수) 인 순서쌍 (x, y)의 개수를 구하는 문제

# x, y의 범위가 최대 10^9 이므로, x와 y를 하나씩 모두 확인하면 시간 초과가 난다.
# 대신 k^n 값을 하나 고정하면 y = x * k^n 으로 y가 x에 의해 하나로 정해진다.
# y가 범위 안에 있어야 하므로
#   l2 <= x * k^n <= r2   →   ceil(l2 / k^n) <= x <= floor(r2 / k^n)
# 이 x의 범위와 [l1, r1]이 겹치는 구간의 정수 개수가, 해당 k^n에서 가능한 순서쌍의 개수이다.

# k >= 2 이므로 k^n은 1, k, k^2, ... 으로 빠르게 커지고,
# k^n > r2 이면 y = x * k^n > r2 가 되어 가능한 x가 없으므로 그 전까지만 확인한다. (최대 약 30번)

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # k, x의 범위, y의 범위 입력 처리
    k, l1, r1, l2, r2 = map(int, input().split())

    # 정답을 저장할 변수 선언
    answer = 0

    # power = k^n 을 1부터 k배씩 키우면서 확인
    power = 1
    while power <= r2:
        # y = x * power 가 [l2, r2] 안에 들어가는 x의 범위를 구하고, [l1, r1]과 겹치는 구간을 계산
        x_low = max(l1, (l2 + power - 1) // power)  # ceil(l2 / power) 과 l1 중 큰 값
        x_high = min(r1, r2 // power)               # floor(r2 / power) 와 r1 중 작은 값

        # 겹치는 구간이 있다면, 구간 안의 정수 개수를 정답에 추가
        if x_low <= x_high:
            answer += x_high - x_low + 1

        power *= k

    # 출력 처리
    print(answer)
