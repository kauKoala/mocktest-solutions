import bisect

# 부분 조합 합을 구하는 재귀 함수
def count_item_comb(arr, current_weight, idx, end):
    global cnt_item
    global c
    # 종료 조건: 탐색이 끝까지 왔을 때
    if idx == end:  
        cnt_item.append(current_weight)  # 지금까지 만든 합을 저장
        return
    
    # 현재 아이템을 선택하지 않고 넘어가는 경우
    count_item_comb(arr, current_weight, idx + 1, end)
    
    # 현재 아이템을 선택하는 경우 (무게 제한 초과시 X)
    if current_weight + arr[idx] <= c:
        count_item_comb(arr, current_weight + arr[idx], idx + 1, end)

n, c = map(int, input().split())
item = list(map(int, input().split()))

cnt = 0  # 최종 가능한 조합 개수

# 아이템이 하나만 있는 경우는 직접 처리
if n == 1:
    if item[0] <= c:
        cnt = 2  # (0, item[0]) -> 빈 선택 + 아이템 선택
    else:
        cnt = 1  # (0) -> 빈 선택만 가능
else:
    mid = n // 2  # 아이템을 반으로 나눔

    # 첫 번째 절반 부분합 계산
    cnt_item = []
    count_item_comb(item, 0, 0, mid)
    cnt_item1 = cnt_item.copy()  # 리스트 복사

    # 두 번째 절반 부분합 계산
    cnt_item = []
    count_item_comb(item, 0, mid, n)
    cnt_item2 = cnt_item.copy()  # 리스트 복사

    # 첫 번째 절반의 부분합을 오름차순 정렬 (이진탐색용)
    cnt_item1.sort()

    # 두 번째 절반에거 각 부분합을 기준으로 첫 번째 절반에서 조건을 만족하는 수 세기
    for val in cnt_item2:
        # c - val 이하인 값이 cnt_item1에 몇 개 있는지 확인
        # 즉, 두 절반의 합이 c 이하인 경우의 수 세기
        cnt += bisect.bisect_right(cnt_item1, c - val)
    
print(cnt)