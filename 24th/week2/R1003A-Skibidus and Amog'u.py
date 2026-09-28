import sys
input = sys.stdin.readline

# 입력 처리
t = int(input())
for _ in range(t):
    w = input().strip()

    # 문자열 맨 끝의 "us"를 제외하고 "i"를 덧붙여 출력
    print(w[:-2] + "i")