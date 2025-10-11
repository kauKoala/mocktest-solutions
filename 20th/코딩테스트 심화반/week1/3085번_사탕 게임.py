n = int(input())

candy = []
for _ in range(n):
    candy.append(list(input()))

max_num = 0  # 연속된 사탕 최대 개수 초기화

# 모든 위치에서 가로/세로 인접 사탕 교환 시도
for i in range(n):
    for j in range(n):
        # 오른쪽과 교환 가능한 경우
        if j < n-1:
            candy[i][j], candy[i][j+1] = candy[i][j+1], candy[i][j]  # 교환

            # 1. 교환한 행(i) 체크
            color, cnt = candy[i][0], 1
            for k in range(1, n):
                if candy[i][k] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[i][k], 1
            max_num = max(max_num, cnt)  # 마지막 연속 체크

            # 2. 교환한 열(j) 체크
            color, cnt = candy[0][j], 1
            for k in range(1, n):
                if candy[k][j] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[k][j], 1
            max_num = max(max_num, cnt)

            # 3. 교환한 열(j+1) 체크
            color, cnt = candy[0][j+1], 1
            for k in range(1, n):
                if candy[k][j+1] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[k][j+1], 1
            max_num = max(max_num, cnt)

            # 교환 원상복구
            candy[i][j], candy[i][j+1] = candy[i][j+1], candy[i][j]

        # 아래와 교환 가능한 경우
        if i < n-1:
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]  # 교환

            # 1. 교환한 행(i) 체크
            color, cnt = candy[i][0], 1
            for k in range(1, n):
                if candy[i][k] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[i][k], 1
            max_num = max(max_num, cnt)

            # 2. 교환한 행(i+1) 체크
            color, cnt = candy[i+1][0], 1
            for k in range(1, n):
                if candy[i+1][k] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[i+1][k], 1
            max_num = max(max_num, cnt)

            # 3. 교환한 열(j) 체크
            color, cnt = candy[0][j], 1
            for k in range(1, n):
                if candy[k][j] == color:
                    cnt += 1
                else:
                    max_num = max(max_num, cnt)
                    color, cnt = candy[k][j], 1
            max_num = max(max_num, cnt)

            # 교환 원상복구
            candy[i][j], candy[i+1][j] = candy[i+1][j], candy[i][j]

# 최댓값 출력
print(max_num)