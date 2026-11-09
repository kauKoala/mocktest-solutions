import sys
from math import gcd
input = sys.stdin.readline

# a[i]와 a[j]가 서로소(최대공약수가 1)인 (i, j) 중 i + j 의 최댓값을 구하는 문제 (i == j 도 가능)

# n은 최대 2 * 10^5 이므로, 모든 (i, j) 쌍을 확인하면 약 4 * 10^10 번으로 시간 초과가 난다.
# 하지만 a[i]의 값은 1 ~ 1000 범위뿐이다.
# 같은 값이 여러 번 나오면, i + j 를 최대로 하려면 그 값의 "가장 마지막 인덱스"만 쓰면 된다.
# 따라서 값마다 마지막 인덱스만 저장해 두고,
# 등장한 값 x, y 쌍을 모두 확인하면서 gcd(x, y) == 1 이면 last[x] + last[y] 로 정답을 갱신한다.
# 최대공약수는 math 모듈의 gcd (유클리드 호제법) 를 사용한다.

# 최대 값 선언
MAX_VAL = 1000

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 배열 길이 n, 배열 a 입력 처리
    n = int(input())
    a = list(map(int, input().split()))

    # 변수 선언
    last = [0] * (MAX_VAL + 1)   # 값 x가 마지막으로 등장한 인덱스 (0이면 등장하지 않음)

    # 인덱스는 문제와 같이 1부터 사용
    for i in range(n):
        last[a[i]] = i + 1   # 뒤에서 나온 인덱스로 계속 덮어쓰므로 마지막 인덱스가 남음

    # 등장한 값만 모아 두기 (1 ~ 1000 을 매번 전부 도는 것보다 빠름)
    values = [x for x in range(1, MAX_VAL + 1) if last[x] != 0]

    # 정답을 저장할 변수 선언 (서로소 쌍이 없으면 -1)
    answer = -1

    # 등장한 값 x, y 쌍을 모두 확인
    for i in range(len(values)):
        x = values[i]
        for j in range(i, len(values)):   # (x, y)와 (y, x)는 결과가 같으므로 j >= i 만 확인
            y = values[j]

            # 서로소라면 인덱스 합으로 정답 갱신
            if gcd(x, y) == 1:
                answer = max(answer, last[x] + last[y])

    # 출력 처리
    print(answer)
