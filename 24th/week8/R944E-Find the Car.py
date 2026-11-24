import sys
input = sys.stdin.readline

# 표지판 위치 a와 도착 시각 b가 주어질 때, 지점 d에 도착하는 시각(소수점 버림)을 구하는 문제

# 1. 표지판 사이에서는 속도가 일정하므로, d가 속한 구간 [a[i-1], a[i]]만 알면 시각을 계산할 수 있다.
#    구간 안에서 이동한 거리 비율만큼 시간이 흐르므로
#      시각 = b[i-1] + (d - a[i-1]) * (b[i] - b[i-1]) // (a[i] - a[i-1])
#    나눗셈을 마지막에 해야 소수점 아래를 잃지 않고 정확히 버림할 수 있다.
# 2. 출발점 (0, 0)을 맨 앞에 추가해 두면, 첫 구간도 같은 식으로 처리할 수 있다.
# 3. 질문 q가 최대 10^5개이므로 질문마다 구간을 처음부터 찾으면 시간 초과가 난다.
#    a는 오름차순이므로, 이분 탐색으로 "d 이상인 첫 번째 a[i]"를 찾는다.


# 이분 탐색 함수
def binary_search(arr, target):
    left = 0
    right = len(arr)

    # 배열에서 타겟보다 크거나 같은 첫 번째 원소의 인덱스를 반환
    while left < right:
        mid = (left + right) // 2

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid

    return left


# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 목적지 n, 표지판 수 k, 질문 수 q 입력 처리
    n, k, q = map(int, input().split())

    # 표지판 위치, 도착 시각 입력 처리 (맨 앞에 출발점 0을 추가)
    a = [0] + list(map(int, input().split()))   # a[i] : i번째 표지판 위치 (a[0] = 0)
    b = [0] + list(map(int, input().split()))   # b[i] : i번째 표지판 도착 시각 (b[0] = 0)

    # 질문 처리
    answers = []   # 질문별 정답을 저장할 리스트
    for _ in range(q):
        d = int(input())

        # d 이상인 첫 번째 표지판 찾기
        i = binary_search(a, d)

        # d가 표지판 위치와 정확히 같다면 그 표지판의 도착 시각이 정답
        if a[i] == d:
            answers.append(b[i])

        # 아니라면 구간 [a[i-1], a[i]] 안에 있으므로 비율로 계산 (곱셈을 먼저, 나눗셈을 나중에)
        else:
            answers.append(b[i - 1] + (d - a[i - 1]) * (b[i] - b[i - 1]) // (a[i] - a[i - 1]))

    # 출력 처리 (공백으로 구분)
    print(*answers)
