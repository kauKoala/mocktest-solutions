import sys
input = sys.stdin.readline

# a = n - b 를 만족하는 양의 정수 순서쌍 (a, b)의 개수를 구하는 문제

# a = n - b 는 a + b = n 과 같고, a와 b는 모두 1 이상이어야 한다.
# b를 1부터 n-1까지 정하면 a = n - b 도 1 이상이 되므로, b로 가능한 값은 n-1개이다.
# b가 정해지면 a는 하나로 정해지므로, 순서쌍의 개수는 n-1개이다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # n 입력 처리
    n = int(input())

    # 순서쌍의 개수 n-1 출력
    print(n - 1)
