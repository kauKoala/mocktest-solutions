enter = []  # 현재 회사에 있는 사람을 저장할 리스트
for i in range(int(input())):
    name, action = input().split()  # 공백을 기준으로 이름과 행동(enter / leave)을 입력받음
    if action == 'enter':  # enter인 경우 enter 리스트에 이름을 넣음
        enter.append(name)
    else:  # leave인 경우 enter 리스트에서 해당 이름 제거
        enter.remove(name)

enter.sort(reverse = True)  # 오름차순으로 정렬
for i in enter:
    print(i)