import sys
input = sys.stdin.readline

# 세 정수 a, b, c 중 하나가 나머지 두 수의 합인지 판별하는 문제

# "하나가 나머지 두 수의 합"이 되는 경우는 다음 3가지뿐이다.
# a + b == c, a + c == b, b + c == a
# 셋 중 하나라도 만족하면 YES, 아니면 NO를 출력한다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 세 정수 입력 처리
    a, b, c = map(int, input().split())

    # 3가지 경우 중 하나라도 만족하는지 확인 후 출력
    if a + b == c or a + c == b or b + c == a:
        print("YES")
    else:
        print("NO")
