word = input()

for i in word:
    if i.islower():  # 소문자인 경우
        print(i.upper(), end="")  # 대문자로 변환해 출력
    else:  # 대문자인 경우
        print(i.lower(), end="")  # 소문자로 변환해 출력