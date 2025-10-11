# 최대공약수 계산 함수 (유클리드 호제법)
def gcd(m, n):
    while n != 0:
        t = m % n
        m, n = n, t
    return abs(m)

for _ in range(int(input())):
    m, n, x, y = map(int, input().split())

    # m과 n의 최소공배수 계산
    lcm = (m * n) // gcd(m, n)
    result = -1  # 결과 초기값 (-1: 조건 만족하는 해 없음)

    # 시작점 설정
    nx, ny = x, x  # nx는 사용 안 하지만 ny와 cnt 사용
    cnt = x        # cnt: 현재 해

    # x 해부터 시작해서 lcm까지 m씩 증가
    while cnt <= lcm:
        # 현재 y 좌표 계산 (n의 주기를 고려)
        if ny % n == 0:
            cy = n
        else:
            cy = ny % n

        # 조건 만족 시 결과 저장하고 종료
        if cy == y:
            result = cnt
            break

        # 다음 후보 해로 이동
        ny += m  
        cnt += m
    
    print(result)