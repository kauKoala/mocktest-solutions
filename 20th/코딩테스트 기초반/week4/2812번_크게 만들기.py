from collections import deque

n, k = map(int, input().split())
number = list(map(int, input()))

stack = deque([])

# 숫자 하나씩 순회
for i in range(n):
    # 현재 숫자가 스택의 마지막 숫자보다 크고, 아직 제거할 k가 남아있다면
    if stack and (number[i] > stack[-1]):
        # 스택의 마지막 숫자를 제거하면서 현재 숫자를 삽입
        while stack and k:
            if number[i] > stack[-1]:
                stack.pop()  # 작거나 같은 수를 제거
                k -= 1  # 제거 횟수 감소
            else:
                break
    
    # 현재 숫자를 스택에 추가
    stack.append(number[i])

# 아직 제거하지 못한 숫자가 남아 있다면 뒤에서 제거
if k:
    print("".join(map(str, list(stack)[:-k])))  # 뒤에서 k개 제거
else:
    print("".join(map(str, list(stack))))  # 그대로 출력