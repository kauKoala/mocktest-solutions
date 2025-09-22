#include <iostream>

using namespace std;

int main() {
    int A, B, N;
    
    cin >> A >> B;
    cin >> N;
    
    int ans = abs(A - B); // abs는 절댓값을 구하는 함수이다.
    int fixed_frequency; // 지정된 주파수
    
    for (int i = 0; i < N; i++) {
        cin >> fixed_frequency;
        
        // 현재 눌러야 하는 최소 버튼수와 지정된 주파수에서 이동하는 버튼수를 비교하여 작은 값을 ans로 저장
        // min(a, b)는 a와 b중 작은 값을 고르는 함수이다.
        // B에서 fixed_frequency까지의 거리에 1을 추가하는 이유는 fixed_frequency로 이동하는 횟수를 고려한 것이다.
        ans = min(ans, abs(B - fixed_frequency) + 1);
    }
    
    cout << ans;
    
    return 0;
}