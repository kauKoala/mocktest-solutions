# 백트래킹 함수 정의
def back_tracking(current_city, current_sum, step):
    global ans  # 최소 비용
    global n  # 도시 개수

    # 모든 도시를 다 돌고 마지막에 시작점(0번 도시)으로 돌아가는 조건
    if step == n - 1:
        # 마지막 도시에서 시작 도시로 가는 길이 없으면 return
        if w[current_city][0] == 0:
            return
        # 가능하다면 전체 비용 계산 후 최솟값 갱신
        ans = min(ans, current_sum + w[current_city][0])
        return
    
    # 아직 방문하지 않은 도시들을 탐색
    for i in range(n):
        # 이미 방문했거나 연결된 경로가 없다면 스킵
        if visited[i] or w[current_city][i] == 0:
            continue

        # 방문 처리
        visited[i] = 1
        # 재귀 호출 (다음 도시로 이동, 거리 누적, 방문 수 + 1)
        back_tracking(i, current_sum + w[current_city][i], step + 1)
        # 백트래킹 (다시 미방문 상태로 되돌림)
        visited[i] = 0

n = int(input())
w = []
ans = 1e9  # 최소 비용을 아주 큰 수로 초기화
for _ in range(n):
    w.append(list(map(int, input().split())))

# 방문 체크 리스트 (0: 미방문, 1: 방문)
visited = [0] * n
visited[0] = 1  # 0번 도시에서 출발

# 0번 도시에서 연결된 다른 도시들을 출발점으로 시작
for i in range(n):
    # 연결된 도시가 없다면 건너뜀
    if w[0][i] == 0:
        continue

    visited[i] = 1  # 도시 i 방문
    back_tracking(i, w[0][i], 1)  # 백트래킹 시작
    visited[i] = 0  # 방문 해제 (백트래킹)

print(ans)