#include <iostream>
#include <string>

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B, W;
    string S;
    
    cin >> N >> B >> W;
    cin >> S;
    
    int ans = 0;
    int i = 0, j = 0;
    int B_cnt = 0, W_cnt = 0;
    
    if (S[0] == 'B') B_cnt++;
    else W_cnt++;
    
    // 투포인터
    while (1) {
        // 두 조건이 맞을 경우 최댓값 갱신
        if (B >= B_cnt && W <= W_cnt) {
            ans = max(ans, j - i + 1);
        }
        if (i == S.size() - 1) break; 
        
        // 검은 조약돌 조건이 맞을 경우 (두 조건 모두 만족해야 하기에, 한 조건으로만 판단해도 상관 없음)
        if (B >= B_cnt || i == j) {
            if (j < S.size() - 1) { // j가 마지막 인덱스가 아닐 경우
                j++;
                if (S[j] == 'B') B_cnt++;
                else W_cnt++;
            }
            else { // j가 마지막 인덱스일 경우
                if (S[i] == 'B') B_cnt--;
                else W_cnt--;
                i++;   
            }
            
        }
        // 검은 조약돌 조건이 맞지 않을 경우
        else if (B < B_cnt) {
            if (S[i] == 'B') B_cnt--;
            else W_cnt--;
            i++;           
        }
    }
    
    cout << ans;
}