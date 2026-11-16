import sys
input = sys.stdin.readline

# 1부터 n까지의 각 수 i에 대해, 배열의 원소를 최소 몇 개 곱해야
# 곱이 정확히 i가 되는지 구하는 문제이다.

# dp[i] = 곱이 i가 되도록 고르는 원소의 최소 개수라 하고,
# 배열에 들어 있는 값 v는 그 원소 하나만 고르면 되므로 dp[v] = 1 이다.

# 곱이 i인 상태에서 배열의 값 d를 하나 더 곱하면 곱이 i*d가 된다.
# 값 1은 곱해도 수가 변하지 않고 개수만 늘어나므로 곱하는 수 d에서 제외한다.
# 그러면 i*d는 항상 i보다 크므로, i를 1부터 오름차순으로 처리하면,
# i를 볼 때 dp[i]는 이미 확정된 값이다.

# 여기서 모든 d를 다 곱해 보면 파이썬에서는 시간 초과가 난다.
# 고른 원소들을 큰 수부터 차례대로 곱한다고 생각하면,
# 새로 곱하는 수 d는 지금까지의 곱 i보다 클 수 없다.
# 따라서 d는 i이하이면서 i*d가 n이하인 값만 보면 된다.


INF = 10**9

# 테스트 케이스 입력 처리
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # 배열에 있는 값은 원소 하나로 만들 수 있다.
    dp = [INF] * (n + 1)
    for v in a:
        dp[v] = 1

    # 곱하는 수로 쓸 값들을 중복 없이 오름차순으로 정리
    mults = []
    for v in range(2, n + 1):
        if dp[v] == 1:
            mults.append(v)

    # 작은 수부터 차례대로, 배열의 값을 하나 더 곱해 보기
    for i in range(2, n + 1):
        # 만들 수 없는 수에서는 더 뻗어 나갈 수 없다.
        if dp[i] == INF:
            continue

        # 곱하는 수 d의 최댓값 (d는 i이하, i*d는 n이하)
        limit = min(i, n // i)

        cnt = dp[i] + 1
        for d in mults:
            # limit을 넘으면 더 큰 d는 볼 필요가 없다.
            if d > limit:
                break

            next_d = i * d
            if cnt < dp[next_d]:
                dp[next_d] = cnt

    # 만들 수 없는 수는 -1로 바꿔서 정답 리스트에 담기
    answer = []
    for i in range(1, n + 1):
        if dp[i] == INF:
            answer.append(-1)
        else:
            answer.append(dp[i])

    # 출력 처리
    print(' '.join(map(str, answer)))

