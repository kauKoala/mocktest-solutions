import sys
input = sys.stdin.readline

# 이진수들의 곱으로 표현될 수 있는 십진수를 구하는 문제


# n의 범위(이진수 표현 기준 십만) 안에 있는 십진수들을 
# 이진수로 변환시켜 배열에 미리 저장해 둔다 = 이진십진수 배열
binary_arr = []
for i in range(2, 33): 
    binary_arr.append(int(bin(i)[2:]))


# 정답을 저장해 둘 배열
# dp[i]가 True면 i는 이진 십진수들의 곱으로 표현 가능
dp = [False] * 100001

# 초기값 삽입
dp[1] = True

for i in range(1, 100001):
    # i가 이진십진수들의 곱으로 표현 가능한 경우
    if dp[i]:

        # 또 다른 이진십진수들이 곱해진 수도 이진십진수 임을 연산
        for binary in binary_arr:
            mult = i * binary

            # n범위를 벗어나는 경우 대입연산을 하지 않기 위한 조건문
            if mult <= 100000:
                dp[mult] = True


# 입력 처리
t = int(input())

for _ in range(t):
    n = int(input())

    # 출력 처리
    if dp[n]:
        print("YES")
    else:
        print("NO")