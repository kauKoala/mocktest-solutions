a, b = map(int, input().split())
n = int(input())

ans = abs(a - b)
for _ in range(n):
    frequency = int(input())  # 지정된 주파수

    # 현재 눌러야 하는 최소 버튼수와 지정된 주파수에서 이동하는 버튼수를 비교하여 작은 값을 ans로 저장
    # b에서 frequency까지의 거리에 1을 추가하는 이유는 frequency로 이동하는 횟수를 고려한 것이다.
    
    ans = min(ans, abs(b - frequency) + 1)

print(ans)