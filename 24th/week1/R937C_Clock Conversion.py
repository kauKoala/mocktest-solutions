import sys
input = sys.stdin.readline

# 입력으로 주어진 24시간을 12시간 포맷으로 전환하는 문제

# 입력처리
t = int(input())

for _ in range(t):
    h, m = input().strip().split(':') # \n 미포함을 위해 strip 매서드를 써 준다

    # 12시를 넘은 오후이면서 시간(hh)이 두 자릿수(22~24시)인 경우
    if h >= "22":
        print(str(int(h)-12) + ":" + m + " PM")

    # 오후이면서 시간이 한 자릿수이어서 앞에 0이 붙는 경우
    elif h >= "13":
        print("0" + str(int(h)-12) + ":" + m + " PM")

    # 12:00~12:59 사이인 경우
    elif h == "12":
        print(h + ":" + m + " PM")

    # 00:00~00:59 사이인 경우
    elif h == "00":
        print("12:" + m + " AM")

    # 01:00~11:59
    else:
        print(h + ":" + m + " AM")

