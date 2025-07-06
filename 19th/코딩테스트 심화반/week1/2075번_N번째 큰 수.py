import heapq

pq = []  # priority queue 사용을 위해 리스트 선언

n = int(input())
for i in range(n):
    row = list(map(int, input().split()))
    
    for val in row:
        heapq.heappush(pq, val)
        if len(pq) > n:  # 리스트의 크기가 n보다 클 경우 n번째 큰 수는 절대로 우선순위 큐의 top이 될 수 없으므로 pop해줌
            heapq.heappop(pq)

print(pq[0])  # 전부 pop하고 난 후의 top이 곧 n번째 큰 수 