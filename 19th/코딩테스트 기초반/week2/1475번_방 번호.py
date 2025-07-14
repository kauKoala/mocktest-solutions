n = list(map(int, input()))
cnt_n = [0] * 10  # 0 ~ 9 숫자의 개수를 저장할 리스트

for i in n:  # 방 이름을 순회하며 숫자 개수를 저장
    cnt_n[i] += 1

result = 0
for i in range(9):
    if i == 6:  # 숫자가 6, 9인 경우 절반 값이 result와 비교 
        if (cnt_n[6] + cnt_n[9]) / 2 > result:
            result = round((cnt_n[6] + cnt_n[9]) / 2 + 0.1)
            # round() 함수는 소수점 이하가 0.5일 때 짝수 쪽으로 반올림되므로 + 0.1을 해서 소수점 이하를 0.6으로 만들어 반올림이 잘 되도록 함
    else:
        if cnt_n[i] > result:
            result = cnt_n[i]

print(result)