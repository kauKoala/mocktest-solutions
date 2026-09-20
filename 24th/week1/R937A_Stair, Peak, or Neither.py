import sys
input = sys.stdin.readline

# 주어진 3개 숫자(a, b, c)가 어떤 모양인지 판단하는 문제

# 입력 처리
t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())

    # 점차 증가하는 계단 모양인 경우 조건 처리
    if a < b < c:
        print("STAIR")

    # 가운데 숫자가 가장 큰 봉우리 모양인 경우 조건 처리
    elif a < b and b > c:
        print("PEAK")

    # 둘 다 아닐 때
    else:
        print("NONE")