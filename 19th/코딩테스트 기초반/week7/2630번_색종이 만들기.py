import sys
input = sys.stdin.readline

n = int(input())

paper = []
# 종이 정보 입력 (0: 파랑, 1: 하양)
for _ in range(n):
    paper.append(list(map(int, input().split())))

cnt_w = 0  # 하양 종이 조각 개수
cnt_b = 0  # 파랑 종이 조각 개수

def check_paper(x, y, size):
    global cnt_w, cnt_b
    blue = 0  # 파랑 체크용 플래그
    white = 0  # 하양 체크용 플래그

    # 현재 영역에 색이 섞였는지 확인
    for i in range(y, y + size):
        for j in range(x, x + size):
            if not paper[i][j]:  # 파랑이면
                blue = 1
            elif paper[i][j]:  # 하양이면
                white = 1
    
    if not blue:  # 파랑이 하나도 없으면 전부 하양
        cnt_b += 1
    elif not white:  # 하양이 하나도 없으면 전부 파랑
        cnt_w += 1
    else:  # 색이 섞였으면 4등분해서 다시 확인
        if size >= 2:
            check_paper(x, y, size // 2)
            check_paper(x, y + size // 2, size // 2)
            check_paper(x + size // 2, y, size // 2)
            check_paper(x + size // 2, y + size // 2, size // 2)

check_paper(0, 0, n)
print(cnt_w)
print(cnt_b)