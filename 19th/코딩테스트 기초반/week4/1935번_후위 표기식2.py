n = int(input())
str = list(input())
s = []  # stack을 사용하기 위해 리스트 선언

alphabet = [0] * 26  # 피연산자를 저장할 알파벳 배열
for i in range(n):
    alphabet[i] = int(input())

for i in str:
    if i >= 'A' and i <= 'Z':  # i가 알파벳 일 때 
        s.append(alphabet[ord(i) - 65])  # stack에 i에 해당하는 수 push (알파벳 순서를 알아내기 위해 ord(i) - 65)
    else:
        tmp1 = s.pop()
        tmp2 = s.pop()
        if i == '+':
            ans = tmp2 + tmp1
        elif i == '-':
            ans = tmp2 - tmp1
        elif i == '*':
            ans = tmp2 * tmp1
        else:
            ans = tmp2 / tmp1
        s.append(ans)

print(f"{s.pop():.2f}")  # 소수점 2자리까지 출력 