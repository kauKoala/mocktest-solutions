num = int(input())

def hanoi(n, a, b, c):
    if n == 1:  # 원판이 1개면 바로 a → c 이동
        print(a, c)
    else:
        # 1) 위에 있는 n-1개의 원판을 보조 기둥(b)로 옮김 (a → b)
        hanoi(n - 1, a, c, b)
        # 2) 가장 큰 원판을 목표 기둥(c)으로 옮김 (a → c)
        print(a, c)
        # 3) 보조 기둥(b)에 있던 n-1개의 원판을 목표 기둥(c)으로 옮김 (b → c)
        hanoi(n - 1, b, a, c)

print(2 ** num - 1)  # 최소 이동 횟수 = 2^n - 1
hanoi(num, 1, 2, 3)  # (n개, 출발 기둥=1, 보조 기둥=2, 도착 기둥=3)