v = []

def back_tracking(idx):
    global sudoku
    
    # 모든 빈칸을 채웠으면 종료
    if idx == len(v):
        return True
    
    i, j = v[idx]
    area_i = i // 3 * 3
    area_j = j // 3 * 3

    for n in range(1, 10):
        possible = True
        
        # 행, 열 검사
        for m in range(9):
            if sudoku[i][m] == n or sudoku[m][j] == n:
                possible = False
                break
        
        # 3x3 구역 검사
        for r in range(area_i, area_i + 3):
            for c in range(area_j, area_j + 3):
                if sudoku[r][c] == n:
                    possible = False
                    break
            if not possible:
                break
        
        if possible:
            sudoku[i][j] = n
            if back_tracking(idx + 1):
                return True
            sudoku[i][j] = 0  # 백트래킹 되돌리기
    
    return False

# 입력 받기
sudoku = [list(map(int, input().split())) for _ in range(9)]

# 빈칸 좌표 저장
for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0:
            v.append((i, j))

# 백트래킹 수행
back_tracking(0)

# 결과 출력
for row in sudoku:
    print(" ".join(map(str, row)))
