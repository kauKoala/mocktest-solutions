h, m, s = map(int, input().split())

for _ in range(int(input())):  # 명령어 개수만큼 반복
    q = input()
    if q == '3':  # 명령어 3: 현재 시각 출력
        print(h, m, s)
    else:
        t, num = q.split()  # 명령어 타입과 값 분리
        num = int(num)

        # 현재 시간을 초 단위로 변환
        total = h * 3600 + m * 60 + s

        if t == '1':  # 명령어 1: 시각을 num초 앞으로 이동
            total += num
        elif t == '2':  # 명령어 2: 시각을 num초 뒤로 이동
            total -= num

        total %= 86400

        # 다시 시, 분, 초로 변환
        h = total // 3600
        m = (total % 3600) // 60
        s = total % 60