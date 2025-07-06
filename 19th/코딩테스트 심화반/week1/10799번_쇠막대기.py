str = list(input())
s = []  # stack 사용을 위한 리스트
cnt = 0  # 쇠막대기의 개수를 저장할 변수 
is_laser = 0  # 레이저인지 쇠막대기인지 판단하기 위한 변수

for i in str:
    if i == '(':  # i가 (면 스택에 push하고, 이전에 (가 push됐다는 의미로 is_laser를 1로 설정
        s.append(i)
        is_laser = 1
    elif is_laser:  # i가 )고 is_laser가 1이면 레이저라는 의미이므로, 이전에 push한 (는 pop하고, 현재 스택에 있는 ( 개수만큼 cnt에 더함. 그리고 is_laser는 0으로 설정
        s.pop()
        cnt += len(s)
        is_laser = 0
    else:  # i가 )고 is_laser가 0이면 쇠막대기가 끝났다는 의미이므로, 스택에서 하나를 pop하고, cnt에 1을 더함
        s.pop()
        cnt += 1

print(cnt)