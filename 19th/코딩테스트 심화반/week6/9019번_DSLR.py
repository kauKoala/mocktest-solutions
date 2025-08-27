from collections import deque

for _ in range(int(input())):
    a, b = map(int, input().split())

    q = deque()
    visited = [0] * 10000  # 0 ~ 9999까지 방문 여부
    q.append((a, ""))  # (현재 숫자, 명령어 기록)

    while q:
        num, cmd = q.popleft()

        if num == b:  # 목표 숫자 도달하면 출력 후 종료
            print(cmd)
            break
        
        # D 연산
        d = (num * 2) % 10000
        if not visited[d]:
            visited[d] = 1
            q.append((d, cmd + 'D'))
        
        # S 연산
        if num == 0:
            s = 9999
        else:
            s = num - 1
        if not visited[s]:
            visited[s] = 1
            q.append((s, cmd + 'S'))
        
        # L 연산
        l = (num * 10 + num // 1000) % 10000
        if not visited[l]:
            visited[l] = 1
            q.append((l, cmd + 'L'))

        # R 연산
        r = num // 10 + (num % 10) * 1000
        if not visited[r]:
            visited[r] = 1
            q.append((r, cmd + 'R'))