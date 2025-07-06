n, q = map(int, input().split())

back_stack = []  # 뒤로 가기 공간
front_stack = []  # 앞으로 가기 공간
current_page = -1  # 현재 페이지 

for _ in range(q):
    job = input()
    if job == 'B':
        if len(back_stack):
            if current_page != -1:
                front_stack.append(current_page)
            current_page = back_stack.pop()
    elif job == 'F':
        if len(front_stack):
            if current_page != -1:
                back_stack.append(current_page)
            current_page = front_stack.pop()
    elif job == 'C':
        if len(back_stack):  # back_stack에 페이지가 있을 경우에만 압축 실행
            back_stack2 = back_stack  # 현재 back_stack을 back_stack2에 복사
            back_stack = [back_stack2[0]]  # back_stack을 첫 번째 페이지만 두고 초기화
            pre_val = back_stack2[0]  # 첫 번째 페이지 번호를 pre_val(이전 페이지 번호를 저장해둘 변수)에 넣어둠 
            for i in range(1, len(back_stack2)):
                if pre_val != back_stack2[i]:  # pre_val과 비교하면서 같지 않을 때만 back_stack에 넣음 
                    back_stack.append(back_stack2[i])
                pre_val = back_stack2[i]
    else:
        a, i = job.split()
        front_stack = []
        if current_page != -1:
            back_stack.append(current_page)
        current_page = int(i)

print(current_page)
if len(back_stack):
    print(' '.join(map(str, back_stack[::-1])))
else:
    print(-1)
if len(front_stack):
    print(' '.join(map(str, front_stack[::-1])))
else:
    print(-1)