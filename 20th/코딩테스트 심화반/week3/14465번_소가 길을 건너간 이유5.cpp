#include <iostream>

using namespace std;

bool broken[100001];

int main() {
    int N, K, B;
    cin >> N >> K >> B;
    
    int broken_idx;
    int fix_cnt = 0;
    for (int i = 0; i < B; i++) {
        cin >> broken_idx;
        if (broken_idx <= K) fix_cnt++; // 1부터 K까지의 fix_cnt를 미리 계산
        broken[broken_idx] = true;
    }
    
    int i = 1, j = K;
    int ans = 100001;
    // 슬라이딩 윈도우
    // 1부터 K
    // 2부터 K + 1
    // ...
    // N - K + 1부터 N
    while (1) {
        if (j == N + 1) break;
        ans = min(ans, fix_cnt);
        
        if (broken[i]) fix_cnt--; // 벗어날 영역이 고장난 신호등인지 확인
        i++;
        j++;
        if (broken[j]) fix_cnt++; // 추가된 영역이 고장난 신호등인지 확인
    }
    
    cout << ans;
}