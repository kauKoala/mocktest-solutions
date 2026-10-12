import sys
input = sys.stdin.readline
 
# 입력받은 n의 각 자리 숫자의 합을 구하는 문제
# 십의 자리 수는 몫 연산으로, 일의 자리 수는 나눗셈 연산으로 구할 수 있다.
 
# 테스트 케이스 입력 처리
t = int(input())
 
for _ in range(t):
    # n 입력 처리
    n = int(input())
 
    # 십의 자리 수와 일의 자리 수 더한 후, 출력
    print(n // 10 + n % 10)