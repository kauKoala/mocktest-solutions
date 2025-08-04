s1, s2 = map(int, input().split())

sample = []
system = []
flag1 = 1
flag2 = 1

# 샘플 테스트 결과 입력 및 비교
for _ in range(s1):
    a, b = map(int, input().split())
    if a != b:
        flag1 = 0  # 하나라도 다르면 통과 실패

# 시스템 테스트 결과 입력 및 비교
for _ in range(s2):
    a, b = map(int, input().split())
    if a != b:
        flag2 = 0  # 하나라도 다르면 통과 실패

if not flag1:
    print('Wrong Answer')  # 샘플 테스트부터 틀림
elif not flag2:
    print('Why Wrong!!!')  # 샘플은 맞췄는데 시스템 테스트에서 틀림
else:
    print('Accepted')  # 샘플, 시스템 테스트 모두 통과