import sys
input = sys.stdin.readline

# 배열의 원소 순서를 바꿔서 순증가(a1 < a2 < ... < an) 배열을 만들 수 있는지 판별하는 문제

# 원소를 오름차순으로 정렬하면, 만들 수 있는 배치 중 가장 증가에 가까운 배치가 된다.
# 정렬한 뒤에도 이웃한 두 원소가 같다면 (a[i] == a[i+1]),
# 같은 값은 어떻게 배치해도 a[i] < a[i+1] 을 만족할 수 없으므로 불가능하다.
# 즉, 배열에 같은 값이 두 번 이상 있으면 NO, 모두 다르면 YES이다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 배열 길이 n, 배열 a 입력 처리
    n = int(input())
    a = list(map(int, input().split()))

    # 같은 값이 이웃하도록 오름차순 정렬
    a.sort()

    # 변수 선언
    success = True   # 순증가 배열을 만들 수 있는지 여부를 저장할 변수

    # 정렬된 배열에서 이웃한 원소 비교
    for i in range(n - 1):

        # 만약 같은 값이 이웃해 있다면
        if a[i] == a[i + 1]:
            success = False   # 순증가 불가능 처리
            break             # 같은 값이 하나라도 있으면 반드시 NO이므로, 더 탐색할 필요 없이 종료

    # 출력 처리
    if success:
        print("YES")
    else:
        print("NO")
