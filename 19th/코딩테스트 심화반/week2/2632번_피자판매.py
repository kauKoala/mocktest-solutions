# 원형 피자에서 가능한 모든 연속 부분합을 구하는 함수
def get_sub_sums(pizza):
    n = len(pizza)
    pizza += pizza  # 피자가 원형이기 때문에 두 배로 늘려서 슬라이싱 가능하게 함
    result = [0]  # 아무 조각도 선택하지 않은 경우인 0

    # 크기 1부터 n-1까지 조각 수에 대해 가능한 합 계산
    for size in range(1, n):
        current = sum(pizza[:size])  # 첫 시작 부분합
        result.append(current)
        for i in range(1, n):
            # 슬라이딩 윈도우로 다음 조각 합 계산
            current = current - pizza[i - 1] + pizza[i + size - 1]
            result.append(current)

    # 전체 피자를 다 고른 경우의 합도 추가
    result.append(sum(pizza[:n]))  
    return result

pizza_size = int(input())
m, n = map(int, input().split())
pizza_a = [int(input()) for _ in range(m)]
pizza_b = [int(input()) for _ in range(n)]

# A와 B에서 가능한 연속 부분합 전부 구하기
sub_a = get_sub_sums(pizza_a)
sub_b = get_sub_sums(pizza_b)

from collections import Counter

# A 피자의 부분합들 개수 세기 (합이 같은 경우 중복 카운트용)
count_a = Counter(sub_a)

cnt = 0

# B 피자의 부분합 하나씩 확인하며, A에서 (목표 - b)가 되는 경우 세기
for b in sub_b:
    cnt += count_a[pizza_size - b]  # b + a = pizza_size → a = pizza_size - b

# 만약 A 전체 or B 전체 피자만으로도 목표 크기 만들 수 있다면, +1 추가
# (이건 앞에서 중복으로 안 세어질 수 있는 단일 경우 처리)
if sum(pizza_a) == pizza_size or sum(pizza_b) == pizza_size:
    cnt += 1

print(cnt)