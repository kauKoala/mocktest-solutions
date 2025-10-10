n = int(input())

num = 666  # 1번 종말의 수
cnt = 0

while (1):
    if '666' in str(num):  # num을 문자열로 만들고, 그 문자열 안에 '666'이 포함되어 있는지 확인
        cnt += 1  # '666'이 포함되어 있다면 cnt를 +1
        if cnt == n:  # cnt가 n이 되면 num을 출력하고 break
            print(num)
            break
    num += 1  # num을 +1 하면서 계속 반복