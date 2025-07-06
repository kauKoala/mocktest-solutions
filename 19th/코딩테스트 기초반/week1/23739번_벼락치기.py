n = int(input())

chapter = []
for _ in range(n):
    chapter.append(int(input()))

cnt = 0  # 공부한 챕터 개수
time = 30  # 기본 시간 30분으로 설정
for i in chapter:
    if time == 0:  # 휴식 중이었다면 다시 공부 시작
        time = 30

    if i <= time:  # i가 현재 시간보다 작다면 전체 챕터 공부 가능
        cnt += 1
        time -= i  # 다음 챕터 공부를 바로 시작해야 하므로 time에서 i를 뺌
    elif i <= time * 2:  # 주어진 시간 동안 절반 이상 공부했울 경우 
        cnt += 1
        time = 0  # i가 현재 time보다 크기 때문에 남은 time은 0
    else:
        time = 0  # 절반 이상도 공부하지 못한 경우

print(cnt)