from collections import deque

s = int(input())

# 방문 체크: visited[화면에 있는 이모티콘 수][클립보드에 있는 이모티콘 수]
visited = [[0] * (s * 2 + 1) for _ in range(s * 2 + 1)]
q = deque()

# 시작 상태: 화면 1개, 클립보드 0개, 시간 0
visited[1][0] = 1
q.append((1, 0, 0))

while q:
    num, clip, time = q.popleft()  # 현재 상태: 화면, 클립보드, 시간

    # 목표 개수 도달 시 시간 출력 후 종료
    if num == s:
        print(time)
        break

    # 1. 화면에 있는 이모티콘을 클립보드에 복사
    if not visited[num][num]:
        visited[num][num] = 1
        q.append((num, num, time + 1))

    # 2. 클립보드에 있는 이모티콘 붙여넣기
    # 화면 합이 최대 범위를 넘지 않고 방문하지 않은 상태이면 진행
    if clip > 0 and num + clip <= s * 2 and not visited[num + clip][clip]:
        visited[num + clip][clip] = 1
        q.append((num + clip, clip, time + 1))

    # 3. 화면에서 이모티콘 하나 삭제
    if num >= 1:
        if not visited[num - 1][clip]:
            visited[num - 1][clip] = 1
            q.append((num - 1, clip, time + 1))