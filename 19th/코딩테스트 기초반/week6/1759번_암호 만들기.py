import sys
input = sys.stdin.readline

l, c = map(int, input().split())

chars = sorted(input().split())

vowels = {'a', 'e', 'i', 'o', 'u'}  # 모음 집합

def backtrack(start_idx, current_pw):
    # 비밀번호 길이가 l에 도달했을 때 조건 검사
    if len(current_pw) == l:
        vowel_cnt = 0
        consonant_cnt = 0

        # 현재 비밀번호에 포함된 모음/자음 개수 세기
        for char in current_pw:
            if char in vowels:
                vowel_cnt += 1
            else:
                consonant_cnt += 1
        
        # 조건: 모음 1개 이상, 자음 2개 이상일 때만 출력
        if vowel_cnt >= 1 and consonant_cnt >= 2:
            print(current_pw)

        return
    
    # start_idx부터 c-1까지 순서대로 문자 선택 (조합 방식)
    for i in range(start_idx, c):
        backtrack(i + 1, current_pw + chars[i])  # 선택한 문자 추가 후 재귀 호출

backtrack(0, "")