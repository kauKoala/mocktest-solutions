n = int(input())
arr = list(map(int, input().split()))

def next_permutation(a):
    i = len(a) - 1

    # 1. 뒤에서부터 감소하는 부분 찾기
    while i > 0 and a[i-1] >= a[i]:
        i -= 1
    
    if i <= 0:  # 마지막 순열이면 False 반환
        return False
    
    # 2. a[i-1]보다 큰 원소 찾기
    j = len(a) - 1
    while a[j] <= a[i-1]:
        j -= 1

    # 3. a[i-1]와 a[j] swap
    a[i-1], a[j] = a[j], a[i-1]

    # 4. i부터 끝까지 뒤집기 (오름차순 정렬 효과)
    j = len(a) - 1
    while i < j:
        a[i], a[j] = a[j], a[i]
        i += 1
        j -= 1
    
    return True

# 다음 순열이 존재하면 출력, 아니면 -1
if next_permutation(arr):
    print(" ".join(map(str, arr)))
else:
    print(-1)