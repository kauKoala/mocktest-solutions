import sys
input = sys.stdin.readline

# 시계의 숫자 a-b를 잇는 빨간 줄과 c-d를 잇는 파란 줄이 교차하는지 판별하는 문제

# 시계 둘레를 a와 b로 자르면, 둘레가 "a에서 b 사이(안쪽)"와 "그 바깥" 두 부분으로 나뉜다.
# - c와 d가 서로 다른 부분에 있으면, 파란 줄이 빨간 줄을 가로질러야 하므로 교차한다.
# - c와 d가 같은 부분에 있으면, 파란 줄은 빨간 줄의 한쪽에만 있으므로 교차하지 않는다.
# 네 수는 모두 다르므로 c, d가 a나 b와 겹치는 경우는 없다.

# a < b가 되도록 맞춰 두면, "a와 b 사이"에 있는지는 a < x < b 로 판별할 수 있다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 네 정수 입력 처리
    a, b, c, d = map(int, input().split())

    # a < b가 되도록 정리
    if a > b:
        a, b = b, a

    # 변수 선언
    c_inside = (a < c < b)   # c가 a와 b 사이에 있는지 여부
    d_inside = (a < d < b)   # d가 a와 b 사이에 있는지 여부

    # c와 d 중 정확히 하나만 a와 b 사이에 있다면 교차
    if c_inside != d_inside:
        print("YES")
    else:
        print("NO")
