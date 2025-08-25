n, k = map(int, input().split())
li = list(range(1, n + 1))

result = []
idx = 0
for i in range(n):
    idx = (idx + k - 1) % len(li)
    result.append(li[idx])
    li.pop(idx)

output = "<" + ", ".join(map(str, result)) + ">"
print(output)