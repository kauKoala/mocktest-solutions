for _ in range(int(input())):
    time = list(input().split())
    ans = []

    for i in time:
        h, m = map(int, i.split(':'))  # 시:분 분리

        # 시침 위치를 분 단위로 변환 (12시간 기준)
        pos_h = h % 12
        pos_h = pos_h * 60 + m

        # 분침 위치를 시침 스케일로 변환
        pos_m = m * 12

        # 두 바늘 사이의 각도 계산
        angle = abs(pos_h - pos_m)
        angle = min(angle, 720 - angle)  # 시계 반대쪽 각도 고려
        
        # (각도, 시, 분, 원본 문자열) 튜플로 저장
        ans.append((angle, h, m, i))
    
    # 각도 기준 정렬, 각도가 같으면 시, 분 순으로 정렬
    ans.sort(key=lambda x: (x[0], x[1], x[2]))

    # 세 번째로 작은 각도를 가진 시각 출력
    print(ans[2][3])