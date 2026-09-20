import sys
input = sys.stdin.readline

# 입력 n값에 따라 격자를 출력하는 문제

# 격자 2n*2n을 탐색하며 출력해도 좋지만,
# 이번에는 행(가로)으로 나누어 풀이한다.

# 입력 처리
t = int(input())

for _ in range(t):
    n = int(input())

    # 짝수행 문자열 구하기
    even = ""
    for col in range(n):
        if col % 2 :
            even = even + ".."
        else :   # 짝수행은 ##으로 시작
            even = even + "##"

    # 홀수행 문자열 구하기
    odd = ".." + even[:-2]

    # 0~n-1 행까지 격자를 출력
    for row in range(n):
        if row % 2:     # 홀수행
            print(odd)
            print(odd)
        else:           # 짝수행
            print(even)
            print(even)