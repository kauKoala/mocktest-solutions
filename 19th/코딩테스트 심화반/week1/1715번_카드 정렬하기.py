import heapq

hq = []
n = int(input())

if n > 1:
    for _ in range(n):
        val = int(input())
        heapq.heappush(hq, val)

    cnt = 0
    while (len(hq) > 1):
        # priority queue를 사용해 작은 두 수부터 더하기
        tmp1 = heapq.heappop(hq)
        tmp2 = heapq.heappop(hq)
        cnt += (tmp1 + tmp2)
        heapq.heappush(hq, (tmp1 + tmp2))

    print(cnt)
else:
    print(0)