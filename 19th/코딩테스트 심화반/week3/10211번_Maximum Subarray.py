for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    
    # 초기 최대합과 현재까지의 합을 배열의 첫 번째 원소로 초기화
    max_sum = x[0]
    current_sum = x[0]

    # 두 번째 원소부터 순회하며 부분합을 계산
    for i in range(1, n):
        # 현재 원소 x[i]를 단독으로 시작할지,
        # 이전까지의 합(current_sum)에 이어붙일지 결정하여 더 큰 값을 선택
        current_sum = max(x[i], current_sum + x[i])
        
        # 지금까지 계산된 최대합보다 current_sum이 크다면 갱신
        max_sum = max(max_sum, current_sum)
    
    print(max_sum)