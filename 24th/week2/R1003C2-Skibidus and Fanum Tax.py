import sys
input = sys.stdin.readline

# 뺄셈 연산을 통해 오름차순 정렬이 가능한지 여부를 구하는 문제

# 이번 값에서 뺄셈 연산을 해도 오름차순 정렬이 유지된다면,
# 뺄셈 연산을 해서 앞의 수를 조금이라도 작게 만드는 것이 오름차순 정렬에 유리하다.
# 따라서 뺄셈 연산을 하는 경우와 안 하는 경우 모두 비교해 오름차순 정렬이 가능한지 판단한다.


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


# 입력처리
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = sorted(list(map(int, input().split()))) # 이진 탐색을 위해 b배열을 오름차순 정렬해 두기

    # 변수 선언
    prev_elem = -sys.maxsize  # 이전 값을 저장할 변수. -가 될 수 있으므로 최대한 작은 정수를 초기값으로 설정.
    success = True           # 오름차순 정렬 가능 여부를 저장하는 변수
    
    for i in range(n):
        # 뺄셈 연산을 하는 경우 / 안 하는 경우를 담을 리스트 선언
        elems = []

        # 이분 탐색으로 b배열에서 뺄셈 연산을 해도 오름차순이 유지되는 값의 인덱스를 찾고,
        j = binary_search(b, prev_elem + a[i])
        if j < m:                     # 찾은 인덱스 범위가 b배열 범위 안이라면 (0 <= j < m )
            elems.append(b[j] - a[i]) # 리스트에 추가

        # 아무것도 안 해도 오름차순이 유지된다면 리스트에 추가
        if a[i] >= prev_elem:
            elems.append(a[i])

        
        # 뺄셈 연산을 해도 / 안 해도 오름차순 정렬이 안 된다면 정렬 실패 처리
        if not elems:
            success = False
            break
            
        # 다음 원소가 더 유리하게 조건을 만족할 수 있도록, 가능한 값 중 최솟값을 선택
        prev_elem = min(elems)


    # 출력 처리
    if success:
        print("YES")
    else:
        print("NO")