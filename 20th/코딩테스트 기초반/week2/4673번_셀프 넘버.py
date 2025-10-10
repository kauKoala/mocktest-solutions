n = 1
arr = []

for i in range(1, 10001):
    num = i + sum(int(j) for j in str(i))  # 숫자 i를 문자열로 만들어 각 자릿수를 sum하고 i를 더함
    arr.append(num)  # 그 수를 배열에 저장함

    if i in arr:  # i를 1부터 10000까지 순회하면서 i가 배열 안에 없을 때만 i를 출력함
        continue
    else:
        print(i)