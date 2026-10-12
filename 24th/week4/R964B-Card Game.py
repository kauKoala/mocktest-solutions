import sys
input = sys.stdin.readline

# 경기가 이루어질 경우의 수는 총 4가지 뿐이므로,
# 조건 처리를 이용해 해결한다.
# 이길 조건은 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=)한다.
 
# 테스트 케이스 입력 처리
t = int(input())
 
for _ in range(t):
    a1, a2, b1, b2 = map(int, input().split())

    # 정답을 저장할 변수 선언
    answer = 0
 
    # a1 vs b1, a2 vs b2
    # 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=) 최종 승리
    if (a1 > b1 and a2 >= b2) or (a1 >= b1 and a2 > b2):
        answer += 2
 
    # a1 vs b2, a2 vs b1
    # 최소 한 번은 이기고(>), 나머지 한 번은 지지 않아야(>=) 최종 승리
    if (a1 > b2 and a2 >= b1) or (a1 >= b2 and a2 > b1):
        answer += 2
 
    # 출력 처리
    print(answer)