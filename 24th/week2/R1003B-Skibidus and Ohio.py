import sys
input = sys.stdin.readline

# 한 번이라도 연속된 문자가 나온다면, 
# 문제 조건에서 랜덤한 수로 바꿀 수 있고, 가능한 최소한의 길이를 구하는 것이므로
# 문자열의 길이는 반드시 1이 된다.

# 입력 처리
t = int(input())
for _ in range(t):
    s = input().strip()

    # 변수 선언
    length = len(s)
    success = False   # 연속된 문자 존재 여부를 저장할 변수

    # 입력 문자열 탐색
    for i in range(length-1):

        # 만약 연속된 문자가 나온다면
        if s[i] == s[i+1]:
            success = True  # 연속된 문자 존재O 처리
            break           # 연속된 문자가 나오면 반드시 1이므로, 더이상 탐색할 이유가 없으니 강제 종료

    # 출력 처리
    if success:
        print(1)
    else:
        print(length)