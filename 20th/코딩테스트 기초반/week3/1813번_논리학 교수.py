n = int(input())
num = list(map(int, input().split()))

true_list = [0] * 51  # 입력 i의 개수

for i in num:
    true_list[i] += 1  # i의 개수를 저장

impossible = 1
for i in range(50, -1, -1):  # n은 50보다 작거나 같기에 최대 값은 50
    # i개의 말이 i개 존재하면 그 말은 참
    # ex) 정확하게 2개의 말은 참이다. 라는 문장에 두 번 나와야만 답이 될 수 있음
    if true_list[i] == i:
        impossible = 0
        print(i)
        break  # 가능한 답이 여러가지일 경우 가장 큰 값을 출력하기 위해 반복문 중단

# 위에서 원하는 답이 나오지 않았을 경우 모순
if impossible:
    print(-1)
