n = int(input())

n_arr = []       # 음수를 저장할 리스트
p_arr = []       # 양수를 저장할 리스트
zero_cnt = 0     # 0의 개수를 세기 위한 변수

# 숫자들을 분류
for _ in range(n):
    i = int(input())
    if i < 0:
        n_arr.append(i)  # 음수
    elif i == 0:
        zero_cnt += 1    # 0
    else:
        p_arr.append(i)  # 양수

n_arr.sort()  # 음수는 오름차순 (작은 수부터)
p_arr.sort()  # 양수도 오름차순 (큰 수부터 pop 하기 위함)

ans = 0  # 최종 결과

# 음수 처리
while len(n_arr) > 1:
    first = n_arr.pop(0)   # 가장 작은 음수
    second = n_arr.pop(0)  # 그 다음 작은 음수
    ans += first * second  # 두 음수를 곱하면 양수가 되므로 이득

# 남은 음수가 하나 있을 경우
if n_arr:
    if not zero_cnt:       # 0이 없으면 그냥 더함
        ans += n_arr[0]
    # 0이 있으면 곱해서 없애는 것과 같으므로 아무 것도 안 함

# 양수 처리
while p_arr:
    first = p_arr.pop()  # 가장 큰 수부터

    if not p_arr:
        ans += first  # 짝이 안 맞으면 그냥 더함
        break

    second = p_arr.pop()

    # 둘 중 하나라도 1이면 더하는 게 이득
    if first != 1 and second != 1:
        ans += first * second
    else:
        ans += first + second

print(ans)  # 최종 결과 출력