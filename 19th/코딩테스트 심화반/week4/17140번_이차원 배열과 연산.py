from collections import defaultdict

r, c, k = map(int, input().split())

# 3x3 초기 배열 입력
arr = [list(map(int, input().split())) for _ in range(3)]
r_num, c_num = 3, 3  # 현재 행과 열 개수

time = 0
while time <= 100:
    # arr[r-1][c-1] == k 인 경우 출력 후 종료
    if r - 1 < r_num and c - 1 < c_num and arr[r - 1][c - 1] == k:
        print(time)
        break

    time += 1

    # R 연산: 행 개수 >= 열 개수일 때
    if r_num >= c_num:
        new_arr = []
        max_len = 0

        for i in range(r_num):
            counter = defaultdict(int)
            for j in range(c_num):
                if arr[i][j] != 0:
                    counter[arr[i][j]] += 1

            # 숫자 등장 횟수 기준 정렬 (개수 오름차순, 숫자 오름차순)
            sorted_items = sorted(counter.items(), key=lambda x: (x[1], x[0]))

            new_row = []
            for a, b in sorted_items:
                new_row.extend([a, b])  # 숫자와 개수 번갈아 저장
            max_len = max(max_len, len(new_row))
            new_arr.append(new_row)

        # 모든 행 길이를 max_len만큼 맞추고, 100 초과시 자름
        for row in new_arr:
            while len(row) < max_len:
                row.append(0)
            if len(row) > 100:
                row[:] = row[:100]

        arr = new_arr
        c_num = min(100, max_len)  # 열 개수 갱신

    else:  # C 연산: 열 개수 > 행 개수
        new_arr = []
        max_len = 0

        for j in range(c_num):
            counter = defaultdict(int)
            for i in range(r_num):
                if arr[i][j] != 0:
                    counter[arr[i][j]] += 1

            sorted_items = sorted(counter.items(), key=lambda x: (x[1], x[0]))

            new_col = []
            for a, b in sorted_items:
                new_col.extend([a, b])
            max_len = max(max_len, len(new_col))
            new_arr.append(new_col)

        # 열 중심 리스트들을 다시 행 중심 2차원 리스트로 변환
        temp = [[0] * c_num for _ in range(min(100, max_len))]
        for j in range(c_num):
            for i in range(len(new_arr[j])):
                if i >= 100:
                    break
                temp[i][j] = new_arr[j][i]

        arr = temp
        r_num = min(100, max_len)  # 행 개수 갱신

else:
    # 100초가 넘도록 조건을 만족하지 못한 경우
    print(-1)
