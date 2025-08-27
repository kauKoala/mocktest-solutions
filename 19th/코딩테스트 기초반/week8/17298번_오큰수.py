n = int(input())
arr = list(map(int, input().split()))

stack = []  # 오큰수를 찾기 위해 인덱스를 저장하는 스택
result = [-1] * n  # 결과 리스트 초기화 (-1로 시작, 오큰수가 없으면 그대로)
for i in range(n):
    if not stack:
        stack.append(i)  # 스택이 비어있으면 현재 인덱스를 넣음
    else:
        # 스택에 값이 있고, 현재 값이 스택 마지막 값보다 크면
        while stack and arr[stack[-1]] < arr[i]:
            idx = stack.pop()  # 오큰수가 발견된 인덱스
            result[idx] = arr[i]  # 그 인덱스의 오큰수를 현재 값으로 업데이트
        stack.append(i)  # 현재 인덱스를 스택에 추가

print(" ".join(map(str, result)))