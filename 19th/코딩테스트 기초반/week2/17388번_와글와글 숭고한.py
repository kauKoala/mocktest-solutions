s, k, h = map(int, input().split())

if (s + k + h) >= 100:  # s + k + h가 100 이상이면 'OK' 출력
    print('OK')
else:
    if min(s, k, h) == s:  # s, k, h중 최솟값이 s와 같으면 'Soongsil' 출력
        print('Soongsil')
    elif min(s, k, h) == k:  # s, k, h중 최솟값이 k와 같으면 'Korea' 출력
        print('Korea')
    else:  # s, k, h중 최솟값이 h와 같으면 'Hanyang' 출력
        print('Hanyang')