n = int(input())
prefix, suffix = input().split('*')

for _ in range(n):
    filename = input()
    if len(filename) < len(prefix) + len(suffix):
        print('NE')
    elif filename.startswith(prefix) and filename.endswith(suffix):
        print("DA")
    else:
        print("NE")

# startswith() 함수는 문자열이 특정 접두사로 시작하는지 판단하는 함수
# endswith() 함수는 문자열이 특정 접미사로 끝나는지 판단하는 함수 