t = int(input())  

for _ in range(t):
    n = int(input())  
    li = []
    for i in range(n):
        row = list(map(int, input().split()))  
        li.append(row)
    
    li.sort()  # 서류 성적을 기준으로 오름차순 정렬

    count = 0              # 선발된 지원자 수
    min = li[0][1]         # 현재까지의 최소 면접 성적 (처음엔 첫 번째 지원자의 면접 성적)
    for i in range(n):
        if min >= li[i][1]:    # 면접 성적이 더 좋거나 같은 경우만 선발
            count += 1
            min = li[i][1]     # 기준을 현재 면접 성적보다 더 낮게 업데이트

    print(count)  # 선발된 인원 출력