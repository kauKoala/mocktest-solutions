from collections import deque

n = int(input())

# 1부터 n까지 카드를 큐에 넣음
q = deque(range(1, n+1))

# 카드가 1장 남을 때까지 반복
while len(q) > 1:
    q.popleft()  # 맨 위 카드 버리기
    q.append(q.popleft())  # 그 다음 카드를 맨 뒤로 옮기기

# 마지막에 남은 카드 출력
print(q[0])