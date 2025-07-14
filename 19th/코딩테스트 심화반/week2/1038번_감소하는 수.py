from itertools import combinations

n = int(input())

number = []
# 감소하는 수의 범위는 0 ~ 9876543210 이므로 1자리부터 10자리까지 존재할 수 있다.
for i in range(1, 11):
    # range(10)은 0 ~ 9까지 숫자 리스트이고, 여기서 i개를 뽑는 모든 조합을 구한다.
    for j in combinations(range(10), i):
        # 조합은 오름차순으로 주어지므로 감소하는 수를 만들기 위해 내림차순으로 정렬한다.
        num = sorted(j, reverse=True)
        # 숫자 리스트를 문자열로 바꿔서 합친 뒤, 다시 정수로 변환한다.
        val = int(''.join(map(str, num)))
        # 위에서 만든 감소하는 수를 리스트에 저장한다.
        number.append(val)

number.sort()

if n >= len(number):
    print(-1)
else:
    print(number[n])