n = int(input())
strong = list(map(int, input().split()))

max_num = 0  # 최댓값 초기화
max_num_idx = []  # 최댓값의 인덱스들을 저장할 리스트

# 최댓값과 그 인덱스들 찾기
for i in range(n):
    if strong[i] > max_num:
        max_num = strong[i]
        max_num_idx = [i]  # 새로운 최댓값이면 인덱스 초기화
    elif strong[i] == max_num:
        max_num_idx.append(i)  # 동일한 최댓값이면 인덱스 추가

# 중앙 위치 설정 (0-indexed 기준에서 가운데 좌우 대칭 비교를 위해 0.5 단위 사용)
middle = n // 2 - 0.5

# 왼쪽 끝 최댓값 인덱스와 오른쪽 끝 최댓값 인덱스를 기준으로 중앙까지의 거리 계산
left_dist = middle - max_num_idx[0]
right_dist = max_num_idx[-1] - middle

if left_dist == right_dist:
    print('X')
elif left_dist > right_dist:
    print('R')
else:
    print('B')