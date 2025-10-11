n = int(input())

# 각 질문 입력: [숫자, 스트라이크, 볼]
question = []
for _ in range(n):
    num, strike, ball = input().split()
    question.append([num, int(strike), int(ball)])

# 후보 숫자 1~9
number = ['1','2','3','4','5','6','7','8','9']

result = 0  # 가능한 정답 개수 초기화

# 모든 3자리 서로 다른 숫자 후보 생성
for a in number:
    for b in number:
        if b == a:
            continue
        for c in number:
            if c == a or c == b:
                continue

            flag = 0  # 현재 후보가 모든 질문을 만족하는지 체크
            for num, strike, ball in question:
                s_check = 0  # 현재 후보와 질문의 스트라이크 개수
                b_check = 0  # 현재 후보와 질문의 볼 개수

                # 1번째 자리 비교
                if num[0] == a:
                    s_check += 1
                elif num[1] == a or num[2] == a:
                    b_check += 1

                # 2번째 자리 비교
                if num[1] == b:
                    s_check += 1
                elif num[0] == b or num[2] == b:
                    b_check += 1

                # 3번째 자리 비교
                if num[2] == c:
                    s_check += 1
                elif num[0] == c or num[1] == c:
                    b_check += 1

                # 질문의 스트라이크/볼과 다르면 후보 불가능
                if s_check != strike or b_check != ball:
                    flag = 1
                    break 
            
            # 모든 질문 만족하면 정답 개수 증가
            if not flag:
                result += 1

# 가능한 정답 개수 출력
print(result)