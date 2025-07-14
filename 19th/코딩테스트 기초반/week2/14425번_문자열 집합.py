n, m = map(int, input().split())

s = []
for i in range(n):  # n개의 문자열을 입력받아 리스트 s에 넣음
    s.append(input())

cnt = 0
for i in range(m):  # m개의 문자열을 입력받으면서 리스트 s에 있는지 확인하고, 있으면 cnt를 + 1함
    check = input()
    if check in s:
        cnt += 1

print(cnt)