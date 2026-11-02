import sys
input = sys.stdin.readline

# 유리창 밖에서 본 문자열 a를, 가게 안에서 봤을 때의 문자열 b로 바꾸는 문제

# 같은 유리창을 반대편에서 보면 좌우가 뒤집혀 보인다.
# 1. 글자의 순서가 반대가 된다. (맨 뒤 글자가 맨 앞에 보인다)
# 2. 각 글자도 좌우 반전된다. p는 q로, q는 p로 보이고, w는 좌우 대칭이라 그대로 w이다.
# 따라서 a를 맨 뒤 글자부터 읽으면서, p와 q는 서로 바꾸고 w는 그대로 b에 붙인다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 문자열 a 입력 처리
    a = input().strip()

    # 변수 선언
    b = ""   # 가게 안에서 본 문자열을 저장할 변수

    # a를 맨 뒤 글자부터 탐색
    for i in range(len(a) - 1, -1, -1):
        if a[i] == 'p':
            b += 'q'    # p는 반전되면 q
        elif a[i] == 'q':
            b += 'p'    # q는 반전되면 p
        else:
            b += 'w'    # w는 반전되어도 w

    # 출력 처리
    print(b)
