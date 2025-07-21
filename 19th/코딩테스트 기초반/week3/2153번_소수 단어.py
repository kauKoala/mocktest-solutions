def is_prime(n):  # 소수 판별 함수
    if n == 1:
        return True 
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

word = input()

total = 0
for i in word:
    if 'a' <= i <= 'z':  # 소문자인 경우
        total += ord(i) - ord('a') + 1
    elif 'A' <= i <= 'Z':  # 대문자인 경우
        total += ord(i) - ord('A') + 27

if is_prime(total):
    print("It is a prime word.")
else:
    print("It is not a prime word.")