import sys
input = sys.stdin.readline

# 두 가지 연산을 원하는 만큼 사용할 수 있을 때,
# 각 쿼리 (l, r)마다 a[l] + ... + a[r] 의 최댓값을 구하는 문제이다.

# 풀이의 편의성을 위해 아래와 같이 가정하겠다.
# 연산1 : a[i]를 a[i+1]로 바꾼다.
# 연산2 : a[i]를 b[i]로 바꾼다.

# 연산1을 반복하면 오른쪽에 있는 값을 왼쪽으로 계속 끌고 올 수 있다.
# 그리고 그 오른쪽 값은 연산2로 미리 b 값으로 바꿔 둘 수도 있다.
# 그렇다면 a[i]는 자기 자신을 포함해 오른쪽에 있는 모든 a[j], b[j] 중 아무 값이나 될 수 있다.

# 따라서 a[i]가 될 수 있는 최댓값을 best[i]라고 하면...
# best[i] = max(a[i], b[i], best[i+1])
# 이며, 뒤에서부터 채우면 O(n)에 구할 수 있다.

# 모든 자리를 동시에 best[i]로 만들 수 있을까?
# best는 왼쪽으로 갈수록 커지거나 같은 배열이므로, 오른쪽 자리부터 차례대로 값을 맞춰 가면 가능하다.
# -> 오른쪽 자리를 먼저 완성하고, 왼쪽 자리는 자기 값 / b 값 / 완성된 오른쪽 값 중 가장 큰 것을 고르면 된다.


# 테스트 케이스 입력 처리
t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    # best = a가 될 수 있는 최댓값
    best = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        best[i] = max(a[i], b[i], best[i + 1])

    # best의 누적합 계산
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + best[i]  # best[0]부터 best[i]까지 더한 값

    # 쿼리 처리
    answer = []
    for _ in range(q):
        l, r = map(int, input().split())

        # l번째부터 r번째까지의 best 합
        answer.append(prefix[r] - prefix[l - 1])

    # 출력 처리
    print(*answer)



