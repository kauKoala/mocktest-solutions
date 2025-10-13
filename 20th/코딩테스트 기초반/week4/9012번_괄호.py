for _ in range(int(input())):
    string = list(input())

    stack = []
    flag = 1  # VPS인지 확인

    for i in string:
        if i == '(':  # '(' 모양이면 스택에 push
            stack.append(i)
        else:  # ')' 모양이고, 스택 내부에 '(' 모양이 존재하면 스택에서 pop
            if stack:
                stack.pop()
            else:  # 스택에 '(' 모양이 존재하지 않을 경우 VPS가 아님
                flag = 0
                break
    
    if flag and not stack:  # VPS이고, 스택이 비어있다면 해당 문자열은 VPS
        print('YES')
    else:
        print('NO')