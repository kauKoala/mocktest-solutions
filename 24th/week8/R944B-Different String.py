import sys
input = sys.stdin.readline

# 문자열 s의 문자 순서를 바꿔서 s와 다른 문자열 r을 만드는 문제 (불가능하면 NO)

# 순서를 바꿔도 항상 s와 같아지는 경우는 모든 문자가 같은 경우뿐이다. (예: aaaaa)
# 서로 다른 문자가 하나라도 있으면, 첫 번째 문자 s[0]과 그 문자와 다른 s[i]의 자리를 바꾸면
# 0번 자리의 문자가 달라지므로 반드시 s와 다른 문자열이 된다.
# 따라서 s[0]과 다른 문자를 앞에서부터 찾아, 찾으면 두 문자를 바꾸고 YES, 못 찾으면 NO를 출력한다.

# 테스트 케이스 입력 처리
t = int(input())

for _ in range(t):
    # 문자열 입력 처리 (문자를 바꾸기 위해 리스트로 저장)
    r = list(input().strip())

    # 변수 선언
    success = False   # s와 다른 문자열을 만들 수 있는지 여부를 저장할 변수

    # s[0]과 다른 문자를 앞에서부터 탐색
    for i in range(1, len(r)):

        # 만약 s[0]과 다른 문자를 찾았다면
        if r[i] != r[0]:
            r[0], r[i] = r[i], r[0]   # 두 문자의 자리를 바꿈
            success = True
            break                     # 한 번만 바꾸면 충분하므로 탐색 종료

    # 출력 처리
    if success:
        print("YES")
        print("".join(r))
    else:
        print("NO")
