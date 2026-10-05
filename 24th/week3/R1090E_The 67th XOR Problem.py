import sys
input = sys.stdin.readline

# 원소 하나를 골라 그 값으로 배열 전체를 XOR하고 지우는 연산을 n-1번 했을 때, 남는 값의 최댓값을 구하는 문제

# 같은 수를 두 번 XOR하면 0이 되어 사라진다. (x ^ x = 0)
# 예를 들어 [a, b, c] 에서 b를 고르면 [a^b, c^b] 가 되고, 여기서 c^b를 고르면
# (a^b)^(c^b) = a^c 만 남는다. 처음에 고른 b는 사라진 것을 볼 수 있다.
# 이처럼 연산을 몇 번 하든 마지막에는 처음 배열의 두 원소를 XOR한 값만 남고,
# 어떤 두 원소든 나머지를 먼저 지우면 마지막까지 남길 수 있다.
# 따라서 두 원소의 XOR 값 중 최댓값을 구하면 된다. (n의 합이 3105 이하라 이중 반복문 가능)

# 입력 처리
t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # 두 원소를 고르는 모든 경우를 확인
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            xor_num = a[i] ^ a[j]

            # 지금까지의 최댓값보다 크다면 갱신
            if xor_num > ans:
                ans = xor_num

    # 출력 처리
    print(ans)
