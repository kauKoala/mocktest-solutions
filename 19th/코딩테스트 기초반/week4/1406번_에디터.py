from collections import deque

front_space = deque(list(input()))
back_space = deque([])

for _ in range(int(input())):
    command = input()  # 명령어 입력
    if command == 'L':  # 명령어가 L일 경우
        if front_space:
            back_space.appendleft(front_space.pop())
    elif command == 'D':  # 명령어가 D일 경우
        if back_space:
            front_space.append(back_space.popleft())
    elif command == 'B':  # 명령어가 B일 경우
        if front_space:
            front_space.pop()
    else:  # 명령어가 L, D, B 모두 아닐 경우 P와 추가 입력받은 값을 공백을 기준으로 나눔
        p, n = command.split()
        front_space.append(n)

print("".join(list(front_space) + list(back_space)))