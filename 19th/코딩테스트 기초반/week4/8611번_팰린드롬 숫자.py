# num을 base(진수)로 변환하여 문자열로 반환하는 함수
def to_base_n(num, base):
    digits = "0123456789"  # 진법 변환 시 사용할 숫자들
    if num == 0:
        return "0"  # 0은 모든 진법에서 0
    result = ''
    while num > 0:
        result = digits[num % base] + result  # 나머지를 앞에 붙여 나감
        num //= base
    return result

# 팰린드롬(회문)인지 확인하는 함수: 문자열이 앞뒤로 같으면 True
def check_palindrome(s):
    return s == s[::-1]

# 입력 받기
n = int(input())
flag = 1  # 팰린드롬을 발견했는지 여부를 체크

# 2진수부터 9진수까지 확인
for i in range(2, 10):
    num = to_base_n(n, i)  # n을 i진수로 변환
    if check_palindrome(num):  # 팰린드롬인지 확인
        print(i, num)  # 진수와 변환된 수 출력
        flag = 0  # 팰린드롬 발견했으므로 flag 0으로 설정

# 10진수로도 팰린드롬인지 확인
if check_palindrome(str(n)):
    flag = 0
    print(10, n)
elif flag:
    print('NIE')  # 어떤 진수에서도 팰린드롬이 아니면 NIE 출력
