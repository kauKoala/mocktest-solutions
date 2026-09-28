import sys
input = sys.stdin.readline

# 알고리즘 문제 보다는 수학 문제에 가깝다.

# 어떤 원소 x가 전체 연결된 배열(n*m)의 pos 번째 위치에 있다고 하자.
# 이 원소 x는 pos 번째 누적 합 S_pos 부터 마지막 S_L까지 총 L-pos+1 번 더해진다.
# 즉, 원소 x가 최종 점수에 기여하는 값은 x*(L-pos+1)이다.

# 각 배열의 길이는 m이다. 어떤 배열 A가 k개의 다른 배열 뒤에 배치된다고 하자.
# k=0 이면 첫 번째, k=1 이면 두 번째 배치이며,
# 이 배열 A의 원소 a1, a2, ..., am 들의 전체 위치는 k*m+1, k*m+2, ..., k*m+m 가 된다.

# 이 배열이 전체 점수에 기여하는 총합을 수식으로 나타내면...
# 시그마[j=1~m](a[j] * (L-(k*m+j)+1))

# 이를 전개해서 분리하면...
# 시그마[j=1~m](a[j] * (L-k*m+j+1)) = (L-k*m+1) * 시그마[j=1~m](a[j]) - 시그마[j=1~m](a[j]*j)
#                                  = (L-k*m+1) * Sk - fixed

# 맨 마지막의 상수항 부분 "-시그마[j=1~m](a[j]*j)" =fixed 은 배열이 어디에 배치되든 변하기 않는 고정된 값이다.
# 따라서 결과값을 최대화하려면, 곱해지는 계수 (L-k*m+1)가 가장 클 때 (즉, k가 작아 앞쪽에 올 때)
# 배열의 합 S가 가장 큰 배열을 배치하면 된다. (=내림차순 정렬)


# 입력 처리
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    # 변수 선언
    L = n * m  # 이어 붙인 배열의 전체 길이
    S_list = [] # 배열의 합(S1, S2, ..., Sk)을 저장할 리스트
    fixed = 0   # 순서와 관계없이 최종적으로 빼야 하는 상수값 (고정 가중합 시그마[j=1~m](a[j]*j) 들의 합)

    # 배열 입력 및 연산 처리
    for _ in range(n):
        arr = list(map(int, input().split()))

        # 배열의 합 (Sk=a1+a2+...+am) 을 리스트에 추가
        S_list.append(sum(arr))
        
        # 배열 내부에서의 가중합 (시그마[j=1~m](a[j]*j)) 을 상수값에 추가
        fixed += sum((j + 1) * arr[j] for j in range(m))
        

    # 배열의 합이 큰 순서대로 앞쪽(k가 작은 위치)에 배치하기 위해 내림차순 정렬
    S_list.sort(reverse=True)

    # 정답 구하기
    ans = 0
    for k in range(n):                     # k번째 배열에 대한
        ans += (L - k * m + 1) * S_list[k] # (L-k*m+1) * Sk 합연산
    ans -= fixed # 순서와 무관하게 고정적으로 빼야 하는 상수값 빼기

    # 출력 처리
    print(ans)
