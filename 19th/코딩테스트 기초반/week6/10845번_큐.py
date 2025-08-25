from collections import deque

q = deque()
for _ in range(int(input())):
    cmd = input()
    if cmd == 'pop':  # 큐의 맨 앞 원소 빼기
        if q:
            print(q.popleft())
        else:
            print(-1)
    elif cmd == 'size':  # 큐 크기 출력
        print(len(q))
    elif cmd == 'empty':  # 큐가 비었는지 확인
        if q:
            print(0)
        else:
            print(1)
    elif cmd == 'front':  # 큐의 맨 앞 원소 확인
        if q:
            print(q[0])
        else:
            print(-1)
    elif cmd == 'back':  # 큐의 맨 뒤 원소 확인
        if q:
            print(q[-1])
        else:
            print(-1)
    else:  # push X 명령 처리
        push, x = cmd.split()
        q.append(x)