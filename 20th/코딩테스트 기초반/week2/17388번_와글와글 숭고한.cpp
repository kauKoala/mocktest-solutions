#include <iostream>
#include <algorithm> // min 함수를 사용하기 위함

using namespace std;

int main() {
    int S, K, H;
    
    cin >> S >> K >> H;
    
    if (S + K + H >= 100) cout << "OK"; // 합이 100이 넘으면 OK 출력
    else {
        if (min({S, K, H}) == S) cout << "Soongsil"; // 최솟값이 S이면 Soongsil 출력
        else if (min({S, K, H}) == K) cout << "Korea"; // 최솟값이 K이면 Korea 출력
        else cout << "Hanyang"; // 최솟값이 H이면 Hanyang 출력
    }
}