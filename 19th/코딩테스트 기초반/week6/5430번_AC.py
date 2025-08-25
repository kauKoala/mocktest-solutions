from collections import deque

for _ in range(int(input())):
    p = list(input())
    n = int(input())
    num = input()
    is_reversed = False  # 현재 뒤집힘 여부 (True면 뒤집힌 상태)
    flag = True  # 에러 여부 표시
    
    if num == '[]':
        numbers = deque()
    else:  # 양쪽 대괄호 제거 후 ',' 기준으로 나누기
        numbers = deque(map(int, num[1:-1].split(',')))

    for i in p:
        if i == 'R':
            is_reversed = not is_reversed
        elif i == 'D':
            if not numbers:  # 비어있으면 에러
                print('error')
                flag = False
                break
            if is_reversed:  # 뒤집힌 상태 → 뒤에서 제거
                numbers.pop()
            else:  # 일반 상태 → 앞에서 제거
                numbers.popleft()
    
    if flag:
        if is_reversed:  # 뒤집힌 상태면 실제로 뒤집기
            numbers.reverse()
        print(f"[{','.join(map(str, numbers))}]")