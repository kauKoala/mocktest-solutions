n, k = map(int, input().split())
dolls = list(map(int, input().split()))

# 라이언 인형의 인덱스를 저장
lion_indices = [i for i, val in enumerate(dolls) if val == 1]

# 라이언 인형 개수가 k개보다 적으면 조건을 만족할 수 없으므로 -1 출력
if len(lion_indices) < k:
    print(-1)
else:
    # 가능한 최소 길이를 저장할 변수 (초기값은 n + 1로 설정)
    min_length = n + 1

    # 연속된 k개의 라이언 인형을 포함하는 모든 구간을 확인
    for i in range(len(lion_indices) - k + 1):
        # 시작 인덱스: i번째 라이언 인형의 인덱스
        start = lion_indices[i]
        # 끝 인덱스: i + k - 1번째 라이언 인형의 인덱스
        end = lion_indices[i + k - 1]
        # 구간 길이 계산 (start부터 end까지 포함하므로 +1)
        length = end - start + 1
        # 최소 길이 갱신
        min_length = min(min_length, length)
    
    print(min_length)