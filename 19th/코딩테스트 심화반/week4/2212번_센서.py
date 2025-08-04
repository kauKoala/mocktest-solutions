import sys

n = int(sys.stdin.readline())           # 센서의 개수 N
k = int(sys.stdin.readline())           # 집중국의 개수 K
sensors = list(map(int, sys.stdin.readline().split()))  # N개의 센서 위치

# 집중국이 센서 개수보다 많거나 같으면, 각 센서에 하나씩 배치하면 되므로 거리합은 0
if k >= n:
    print(0)
    exit()

sensors.sort()  # 센서를 위치 기준으로 정렬

# 인접한 센서 간의 거리 차이를 모두 구함
diff = [sensors[i+1] - sensors[i] for i in range(n - 1)]

# 큰 거리부터 자르면 최소 거리를 만들 수 있음 → 내림차순 정렬
diff.sort(reverse=True)

# 가장 큰 거리들 (K-1개)을 자르고, 나머지 거리들을 합산 → 최소 수신 거리
print(sum(diff[k-1:]))