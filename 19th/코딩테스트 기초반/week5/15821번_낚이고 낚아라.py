n, k = map(int, input().split())

polygon = []
for i in range(n):
    p = int(input())
    xy = list(map(int, input().split()))

    # 각 꼭짓점에서 원점까지 거리^2 중 가장 큰 값 저장
    polygon.append(max(xy[2 * j] ** 2 + xy[2 * j + 1] ** 2 for j in range(len(xy) // 2)))

# 거리 제곱값을 오름차순 정렬
polygon.sort()

# k번째로 가까운 (정확히는 작은 거리^2 값) 출력
# 소수점은 항상 ".00"으로 출력
print(polygon[k-1], '.00', sep="")