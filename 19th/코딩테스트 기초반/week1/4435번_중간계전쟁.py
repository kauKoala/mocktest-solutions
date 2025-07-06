t = int(input())

for i in range(t):
    # 간달프 군대의 종족의 수 입력
    g1, g2, g3, g4, g5, g6 = map(int, input().split())
    # 사우론 군대의 종족의 수 입력
    s1, s2, s3, s4, s5, s6, s7 = map(int, input().split())

    # 간달프 군대의 종족의 점수 계산
    g_score = g1 * 1 + g2 * 2 + g3 * 3 + g4 * 3 + g5 * 4 + g6 * 10
    # 사우론 군대의 종족의 점수 계산
    s_score = s1 * 1 + s2 * 2 + s3 * 2 + s4 * 2 + s5 * 3 + s6 * 5 + s7 * 10

    print('Battle', i+1, end='')
    if g_score > s_score:
        print(': Good triumphs over Evil')
    elif g_score < s_score:
        print(': Evil eradicates all trace of Good')
    else:
        print(': No victor on this battle field')