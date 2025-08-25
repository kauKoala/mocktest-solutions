n, k = map(int, input().split())
li = list(range(1, n + 1))

result = []
idx = 0
for i in range(n):
    # k번째 사람을 찾기 위해 인덱스 계산 (순환 구조)
    idx = (idx + k - 1) % len(li)
    result.append(li[idx])  # 제거된 사람을 결과에 추가
    li.pop(idx)  # 리스트에서 제거

output = "<" + ", ".join(map(str, result)) + ">"
print(output)